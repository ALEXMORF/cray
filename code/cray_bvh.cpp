inline bound
BoundTriangle(packed_triangle Triangle)
{
    bound Bound = {};
    
    Bound.Min = Min(Triangle.A, Triangle.B);
    Bound.Max = Max(Triangle.A, Triangle.B);
    Bound.Min = Min(Bound.Min, Triangle.C);
    Bound.Max = Max(Bound.Max, Triangle.C);
    
    Bound.IsValid = true;
    return Bound;
}

inline bound
Union(bound A, bound B)
{
    bound Bound = {};
    
    ASSERT(A.IsValid || B.IsValid);
    if (!A.IsValid)
    {
        return B;
    }
    if (!B.IsValid)
    {
        return A;
    }
    
    Bound.Min = Min(A.Min, B.Min);
    Bound.Max = Max(A.Max, B.Max);
    
    Bound.IsValid = true;
    return Bound;
}

inline v3
CalcTriangleCentroid(packed_triangle Triangle)
{
    v3 Centroid = {};
    
    f32 U = 0.3333f;
    f32 V = U;
    
    Centroid = U * Triangle.A + V * Triangle.B + (1.0f - U - V) * Triangle.C;
    
    return Centroid;
}

int ComparePrimitive(const void *DataA, const void *DataB)
{
    primitive *A = (primitive *)DataA;
    primitive *B = (primitive *)DataB;
    
    if (A->Centroid.Data[GlobalPartitionAxis] < 
        B->Centroid.Data[GlobalPartitionAxis])
    {
        return -1;
    }
    else if (A->Centroid.Data[GlobalPartitionAxis] > 
             B->Centroid.Data[GlobalPartitionAxis])
    {
        return 1;
    }
    
    return 0;
}

internal bvh_node *
ConstructBVH(primitive *Prims, int StartIndex, int Count, memory_arena *Arena)
{
    bvh_node *Node = PushStruct(Arena, bvh_node);
    *Node = {};
    
    bound TotalBound = {};
    for (int PrimIndex = StartIndex; PrimIndex < StartIndex+Count; ++PrimIndex)
    {
        TotalBound = Union(TotalBound, Prims[PrimIndex].Bound);
    }
    ASSERT(TotalBound.IsValid);
    Node->Bound = TotalBound;
    
    if (Count > 5)
    {
        f32 DimX = TotalBound.Max.X - TotalBound.Min.X;
        f32 DimY = TotalBound.Max.Y - TotalBound.Min.Y;
        f32 DimZ = TotalBound.Max.Z - TotalBound.Min.Z;
        
        f32 MaxDim = DimX;
        axis PartitionAxis = AXIS_X;
        if (DimY > MaxDim) 
        {
            MaxDim = DimY;
            PartitionAxis = AXIS_Y;
        }
        if (DimZ > MaxDim) 
        {
            MaxDim = DimZ;
            PartitionAxis = AXIS_Z;
        }
        
        GlobalPartitionAxis = PartitionAxis;
        qsort(Prims+StartIndex, Count, sizeof(primitive), ComparePrimitive);
        
        int LeftCount = Count / 2;
        int RightCount = Count - LeftCount;
        
        Node->PrimitiveCount = -1;
        Node->Left = ConstructBVH(Prims, StartIndex, LeftCount, Arena);
        Node->Right = ConstructBVH(Prims, StartIndex+LeftCount, RightCount, Arena);
    }
    else
    {
        Node->PrimitiveOffset = StartIndex;
        Node->PrimitiveCount = Count;
    }
    
    return Node;
}

internal int
CountNodes(bvh_node *Node)
{
    if (!Node) return 0;
    return 1 + CountNodes(Node->Left) + CountNodes(Node->Right);
}

internal void
Flatten(bvh_node *Node, bvh_entry *Array, int *Offset)
{
    if (!Node) return;
    
    int CurrIndex = *Offset;
    *Offset = *Offset + 1;
    Array[CurrIndex].PrimitiveCount = Node->PrimitiveCount;
    Array[CurrIndex].BoundMin = Node->Bound.Min;
    Array[CurrIndex].BoundMax = Node->Bound.Max;
    
    if (Node->PrimitiveCount == -1)
    {
        Flatten(Node->Left, Array, Offset);
        Array[CurrIndex].SecondChildOffset = *Offset;
        Flatten(Node->Right, Array, Offset);
    }
    else
    {
        Array[CurrIndex].PrimitiveOffset = Node->PrimitiveOffset;
    }
}

internal linear_bvh
ConstructLinearBVH(packed_triangle *Triangles, int Count, memory_arena *Arena)
{
    linear_bvh Result = {};
    
    //NOTE(chen): construct BVH
    primitive *Prims = PushTempArray(Count, primitive);
    for (int PrimIndex = 0; PrimIndex < Count; ++PrimIndex)
    {
        primitive *Prim = Prims + PrimIndex;
        Prim->TriIndex = PrimIndex;
        Prim->Bound = BoundTriangle(Triangles[PrimIndex]);
        Prim->Centroid = CalcTriangleCentroid(Triangles[PrimIndex]);
    }
    bvh_node *Root = ConstructBVH(Prims, 0, Count, &GlobalTempArena);
    
    //NOTE(chen): flatten BVH
    Result.Count = CountNodes(Root);
    Result.Data = PushArray(Arena, Result.Count, bvh_entry);
    int Offset = 0;
    Flatten(Root, Result.Data, &Offset);
    
    //NOTE(chen): resort triangles to match order of primitives
    packed_triangle *SortedTriangles = PushTempArray(Count, packed_triangle);
    for (int PrimIndex = 0; PrimIndex < Count; ++PrimIndex)
    {
        int SortedIndex = Prims[PrimIndex].TriIndex;
        SortedTriangles[PrimIndex] = Triangles[SortedIndex];
    }
    for (int TriIndex = 0; TriIndex < Count; ++TriIndex)
    {
        Triangles[TriIndex] = SortedTriangles[TriIndex];
    }
    
    return Result;
}