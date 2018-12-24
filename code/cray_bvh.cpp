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

int CompareTriangle(const void *DataA, const void *DataB)
{
    packed_triangle A = *(packed_triangle *)DataA;
    packed_triangle B = *(packed_triangle *)DataB;
    
    f32 U = 0.3333f;
    f32 V = 0.3333f;
    v3 CentroidA = U * A.A + V * A.B + (1.0f - U - V) * A.C;
    v3 CentroidB = U * B.A + V * B.B + (1.0f - U - V) * B.C;
    
    if (CentroidA.Data[GlobalPartitionAxis] < 
        CentroidB.Data[GlobalPartitionAxis])
    {
        return -1;
    }
    else if (CentroidA.Data[GlobalPartitionAxis] > 
             CentroidB.Data[GlobalPartitionAxis])
    {
        return 1;
    }
    
    return 0;
}

internal bvh_node *
ConstructBVH(packed_triangle *Triangles, int StartIndex, int Count, 
             memory_arena *Arena)
{
    bvh_node *Node = PushStruct(Arena, bvh_node);
    *Node = {};
    
    bound TotalBound = {};
    for (int TriIndex = StartIndex; TriIndex < StartIndex+Count; ++TriIndex)
    {
        bound TriBound = BoundTriangle(Triangles[TriIndex]);
        TotalBound = Union(TotalBound, TriBound);
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
        qsort(Triangles+StartIndex, Count, sizeof(packed_triangle), CompareTriangle);
        
        int LeftCount = Count / 2;
        int RightCount = Count - LeftCount;
        
        Node->PrimitiveCount = -1;
        Node->Left = ConstructBVH(Triangles, StartIndex, LeftCount, Arena);
        Node->Right = ConstructBVH(Triangles, StartIndex+LeftCount, RightCount, Arena);
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
    Array[CurrIndex].Min = Node->Bound.Min;
    Array[CurrIndex].Max = Node->Bound.Max;
    
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
ConstructLinearBVH(packed_triangle *Triangles, int StartIndex, 
                   int Count, memory_arena *Arena)
{
    linear_bvh Result = {};
    
    bvh_node *Root = ConstructBVH(Triangles, StartIndex, 
                                  Count, &GlobalTempArena);
    Result.Count = CountNodes(Root);
    Result.Data = PushArray(Arena, Result.Count, bvh_entry);
    
    int Offset = 0;
    Flatten(Root, Result.Data, &Offset);
    
    return Result;
}