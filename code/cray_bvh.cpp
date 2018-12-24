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

inline f32
CalcSurfaceArea(bound Bound)
{
    v3 Dim = Bound.Max - Bound.Min;
    
    f32 TopFaces = 2.0f * Dim.X * Dim.Z;
    f32 SideFaces = 2.0f * Dim.Y * Dim.Z;
    f32 FrontBackFaces = 2.0f * Dim.X * Dim.Y;
    
    return TopFaces + SideFaces + FrontBackFaces;
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

inline bound
Union(bound A, v3 P)
{
    bound Bound = {};
    
    if (!A.IsValid)
    {
        Bound.Min = P;
        Bound.Max = P;
    }
    else
    {
        Bound.Min = Min(A.Min, P);
        Bound.Max = Max(A.Max, P);
    }
    
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

internal int
PartitionLeftSAH(primitive *Prims, int StartIndex, int Count, 
                 axis Axis, f32 MinCentroid, f32 MaxCentroid, 
                 bound TotalBound)
{
    bucket Buckets[12] = {};
    int BucketCount = ARRAY_COUNT(Buckets);
    f32 BucketInterval = (MaxCentroid - MinCentroid) / (f32)BucketCount;
    
    for (int PrimIndex = StartIndex; PrimIndex < StartIndex+Count; ++PrimIndex)
    {
        f32 Centroid = Prims[PrimIndex].Centroid.Data[Axis];
        int OwnerBucketIndex = (int)((Centroid - MinCentroid) / BucketInterval);
        if (OwnerBucketIndex == BucketCount) 
        {
            OwnerBucketIndex = BucketCount - 1;
        }
        ASSERT(OwnerBucketIndex >= 0 && OwnerBucketIndex < BucketCount);
        
        Buckets[OwnerBucketIndex].PrimCount += 1;
        Buckets[OwnerBucketIndex].Bound = Union(Buckets[OwnerBucketIndex].Bound, Prims[PrimIndex].Bound);
    }
    
    int MinCostLeftPrimCount = -1;
    f32 MinCost = 10e31;
    for (int CutIndex = 0; CutIndex < BucketCount-1; ++CutIndex)
    {
        int LeftBucketCount = CutIndex + 1;
        int RightBucketCount = BucketCount - LeftBucketCount;
        
        bound LeftBound = {};
        int LeftPrimCount = 0;
        for (int BucketIndex = 0; BucketIndex < LeftBucketCount; ++BucketIndex)
        {
            LeftBound = Union(LeftBound, Buckets[BucketIndex].Bound);
            LeftPrimCount += Buckets[BucketIndex].PrimCount;
        }
        
        bound RightBound = {};
        int RightPrimCount = 0;
        for (int BucketIndex = 0; BucketIndex < RightBucketCount; ++BucketIndex)
        {
            RightBound = Union(RightBound, Buckets[BucketIndex].Bound);
            RightPrimCount += Buckets[BucketIndex].PrimCount;
        }
        
        f32 TotalBoundSurfaceArea = CalcSurfaceArea(TotalBound);
        f32 HitLeftProbability = CalcSurfaceArea(LeftBound)/ TotalBoundSurfaceArea;
        f32 HitRightProbability = CalcSurfaceArea(RightBound) / TotalBoundSurfaceArea;
        
        f32 CutCost = 0.125f + (f32)LeftPrimCount * HitLeftProbability + (f32)RightPrimCount * HitRightProbability;
        
        if (CutCost < MinCost)
        {
            MinCost = CutCost;
            MinCostLeftPrimCount = LeftPrimCount;
        }
    }
    ASSERT(MinCostLeftPrimCount != -1);
    
    return MinCostLeftPrimCount;
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
    Node->Bound = TotalBound;
    
    if (Count > 5)
    {
        ASSERT(TotalBound.IsValid);
        
        bound CentroidBound = {};
        for (int PrimIndex = StartIndex; PrimIndex < StartIndex+Count; ++PrimIndex)
        {
            CentroidBound = Union(CentroidBound, Prims[PrimIndex].Centroid);
        }
        
        f32 RangeX = CentroidBound.Max.X - CentroidBound.Min.X;
        f32 RangeY = CentroidBound.Max.Y - CentroidBound.Min.Y;
        f32 RangeZ = CentroidBound.Max.Z - CentroidBound.Min.Z;
        
        f32 MaxRange = RangeX;
        axis PartitionAxis = AXIS_X;
        if (RangeY > MaxRange) 
        {
            MaxRange = RangeY;
            PartitionAxis = AXIS_Y;
        }
        if (RangeZ > MaxRange) 
        {
            MaxRange = RangeZ;
            PartitionAxis = AXIS_Z;
        }
        
        GlobalPartitionAxis = PartitionAxis;
        qsort(Prims+StartIndex, Count, sizeof(primitive), ComparePrimitive);
        
        int LeftCount = PartitionLeftSAH(Prims, StartIndex, Count, 
                                         PartitionAxis, 
                                         CentroidBound.Min.Data[PartitionAxis],
                                         CentroidBound.Max.Data[PartitionAxis],
                                         TotalBound);
        int RightCount = Count - LeftCount;
        
        //NOTE(chen): can't cut anymore, fallback to equal cut
        if (LeftCount == Count || RightCount == Count)
        {
            ASSERT(!"shiz");
            LeftCount = Count / 2;
            RightCount = Count - LeftCount;
        }
        
        Node->PrimitiveCount = -1;
        Node->PartitionAxis = PartitionAxis;
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
        Array[CurrIndex].Axis = Node->PartitionAxis;
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