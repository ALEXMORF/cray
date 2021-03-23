inline bound
BoundTriangle(triangle Triangle)
{
    bound Bound = {};
    
    Bound.Min = Min(Min(Triangle.A, Triangle.B), Triangle.C);
    Bound.Max = Max(Max(Triangle.A, Triangle.B), Triangle.C);
    
    Bound.IsValid = true;
    return Bound;
}

inline bound
DefaultBound() {
    bound Result = {};
    Result.Min = {FLT_MAX, FLT_MAX, FLT_MAX};
    Result.Max = {-FLT_MAX, -FLT_MAX, -FLT_MAX};
    return Result;
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

internal f32
ChooseBestCutSAH(primitive *Prims, int StartIndex, int Count, 
                 axis Axis, f32 MinCentroid, f32 MaxCentroid, 
                 bound TotalBound, f32 *MinCost_Out)
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
    
    f32 Cut = -1.0f;
    f32 MinCost = 10e31f;
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
            Cut = MinCentroid + (f32)(CutIndex+1) * BucketInterval;
        }
    }
    ASSERT(Cut != -1.0f);
    
    *MinCost_Out = MinCost;
    return Cut;
}

internal int 
Partition(primitive *Prims, int Count, f32 Cut, axis Axis)
{
    int LeftCount = 0;
    
    for (int PrimIndex = 0; PrimIndex < Count; ++PrimIndex)
    {
        if (Prims[PrimIndex].Centroid.Data[Axis] < Cut)
        {
            //NOTE(chen): swap Prims[PrimIndex] and Prims[LeftCount]
            primitive CurrPrim = Prims[PrimIndex];
            Prims[PrimIndex] = Prims[LeftCount];
            Prims[LeftCount] = CurrPrim;
            
            LeftCount += 1;
        }
    }
    
    return LeftCount;
}

inline bvh_node *
AllocBvhNode() {
    bvh_node *Node = PushTempStruct(bvh_node);
    *Node = {};
    Node->Left = 0;
    Node->Right = 0;
    return Node;
}

inline bool
IsInternal(bvh_node *Node) {
    return Node->PrimitiveCount == -1;
}

inline bool
IsLeaf(bvh_node *Node) {
    return !IsInternal(Node);
}

internal bvh_node *
ConstructBVHTree(primitive *Prims, int StartIndex, int Count)
{
    bvh_node *Node = AllocBvhNode();
    
    bound TotalBound = DefaultBound();
    for (int PrimIndex = StartIndex; PrimIndex < StartIndex+Count; ++PrimIndex)
    {
        TotalBound = Union(TotalBound, Prims[PrimIndex].Bound);
    }
    Node->Bound = TotalBound;
    
    bound CentroidBound = DefaultBound();
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
    
    if (Count > 5 && MaxRange > 0.001f && CalcSurfaceArea(TotalBound) != 0.0f)
    {
        f32 MinCost;
        f32 Cut = ChooseBestCutSAH(Prims, StartIndex, Count, 
                                   PartitionAxis, 
                                   CentroidBound.Min.Data[PartitionAxis],
                                   CentroidBound.Max.Data[PartitionAxis],
                                   TotalBound, &MinCost);
        
        int LeftCount = Partition(Prims+StartIndex, Count, Cut, PartitionAxis);
        int RightCount = Count - LeftCount;
        
        if (LeftCount == 0 || RightCount == 0)
        {
            Node->PrimitiveOffset = StartIndex;
            Node->PrimitiveCount = Count;
            return Node;
        }
        
        Node->PrimitiveCount = -1;
        Node->PartitionAxis = PartitionAxis;
        Node->Left = ConstructBVHTree(Prims, StartIndex, LeftCount);
        Node->Right = ConstructBVHTree(Prims, StartIndex+LeftCount, RightCount);
    }
    else
    {
        Node->PrimitiveOffset = StartIndex;
        Node->PrimitiveCount = Count;
    }
    
    return Node;
}

internal bvh_node *
BuildUpperSah(primitive *Prims, int StartIndex, int Count)
{
    bvh_node *Node = AllocBvhNode();
    
    bound TotalBound = DefaultBound();
    for (int PrimIndex = StartIndex; PrimIndex < StartIndex+Count; ++PrimIndex)
    {
        TotalBound = Union(TotalBound, Prims[PrimIndex].Bound);
    }
    Node->Bound = TotalBound;
    
    bound CentroidBound = DefaultBound();
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
    
    if (Count > 1 && MaxRange > 0.001f && CalcSurfaceArea(TotalBound) != 0.0f)
    {
        int LeftCount = 0;

        if (MaxRange > 0.001f && CalcSurfaceArea(TotalBound) != 0.0f) { // SAH split
            f32 MinCost;
            f32 Cut = ChooseBestCutSAH(Prims, StartIndex, Count, 
                    PartitionAxis, 
                    CentroidBound.Min.Data[PartitionAxis],
                    CentroidBound.Max.Data[PartitionAxis],
                    TotalBound, &MinCost);

            LeftCount = Partition(Prims+StartIndex, Count, Cut, PartitionAxis);

            if (LeftCount == 0) {
                LeftCount = Count / 2;
            }
        } else { // middle split
            LeftCount = Count / 2;
        }

        int RightCount = Count - LeftCount;

        ASSERT(LeftCount != 0);
        ASSERT(RightCount != 0);
        
        Node->PrimitiveCount = -1;
        Node->PartitionAxis = PartitionAxis;
        Node->Left = BuildUpperSah(Prims, StartIndex, LeftCount);
        Node->Right = BuildUpperSah(Prims, StartIndex+LeftCount, RightCount);
    }
    else
    {
        Node->PrimitiveOffset = StartIndex;
        Node->PrimitiveCount = Count;
    }
    
    return Node;
}


inline u32 LeftShift3(u32 x) {
    if (x == (1 << 10)) --x;
    x = (x | (x << 16)) & 0b00000011000000000000000011111111;
    x = (x | (x <<  8)) & 0b00000011000000001111000000001111;
    x = (x | (x <<  4)) & 0b00000011000011000011000011000011;
    x = (x | (x <<  2)) & 0b00001001001001001001001001001001;
    return x;
}

u32 EncodeMorton3(u32 *Values) {
    u32 Result = 0;
    Result |= LeftShift3(Values[0]);
    Result |= LeftShift3(Values[1]) << 1;
    Result |= LeftShift3(Values[2]) << 2;
    return Result;
}

void RadixSort(primitive *Prims, int Count) {
    const int BitsPerPass = 8;
    const int PassCount = 4;
    const u32 BucketCount = 1 << BitsPerPass;

    primitive *Temp = BufInit(Count, primitive);

    for (int PassI = 0; PassI < PassCount; ++PassI) {
        primitive *Src = (PassI & 1)? Temp: Prims;
        primitive *Dest = (PassI & 1)? Prims: Temp;

        u32 Mask = BITS(BitsPerPass);
        int Shift = PassI * BitsPerPass;

        u64 Counts[BucketCount] = {};
        for (int PrimI = 0; PrimI < Count; ++PrimI) {
            int Key = (Src[PrimI].Code >> Shift) & Mask;
            Counts[Key] += 1;
        }

        u64 Offsets[BucketCount] = {};
        for (int I = 1; I < BucketCount; ++I) {
            Offsets[I] = Offsets[I-1] + Counts[I-1];
        }

        for (int PrimI = 0; PrimI < Count; ++PrimI) {
            int Key = (Src[PrimI].Code >> Shift) & Mask;
            Dest[Offsets[Key]++] = Src[PrimI];
        }
    }

    for (int I = 1; I < Count; ++I) {
        ASSERT(Prims[I].Code >= Prims[I-1].Code);
    }

    BufFree(Temp);
}

int GetBit(u32 Value, int BitIndex) {
    return (Value >> BitIndex) & 1ul;
}

internal bvh_node *
EmitLBVH(primitive *Prims, int Begin, int Count, int BitIndex) {
    if (BitIndex == -1 || Count < 5) {
        bvh_node *Node = AllocBvhNode();

        Node->PrimitiveOffset = Begin;
        Node->PrimitiveCount = Count;
        Node->Bound = DefaultBound();
        for (int I = Begin; I < Begin + Count; ++I) {
            Node->Bound = Union(Node->Bound, Prims[I].Bound);
        }

        return Node;
    }

    int Last = Begin + Count - 1;
    if (GetBit(Prims[Begin].Code, BitIndex) != GetBit(Prims[Last].Code, BitIndex)) {

        int First = Begin;
        for (;;) {
            int Middle = (First + Last) / 2;
            if (First == Middle || Last == Middle) {
                break;
            }

            if (GetBit(Prims[First].Code, BitIndex) != GetBit(Prims[Middle].Code, BitIndex)) {
                Last = Middle;
            } else {
                First = Middle;
            }
        }

        bvh_node *Node = AllocBvhNode();

        int LeftCount = First - Begin + 1;
        Node->PrimitiveCount = -1;
        Node->Left = EmitLBVH(Prims, Begin, LeftCount, BitIndex - 1);
        Node->Right = EmitLBVH(Prims, Begin + LeftCount, Count - LeftCount, BitIndex - 1);

        Node->Bound = Union(Node->Left->Bound, Node->Right->Bound);
        Node->PartitionAxis = axis(BitIndex % 3);

        return Node;
    } else {
        //NOTE(chen): cannot divide prims at this level, go  deeper
        return EmitLBVH(Prims, Begin, Count, BitIndex - 1);
    }
}

internal void
MergeUpperTreeAndLowerTrees(bvh_node *UpperNode, primitive *SortedPrims, bvh_treelet *Treelets) {
    if (!UpperNode) return;

    if (IsInternal(UpperNode)) {
        if (bvh_node *Left = UpperNode->Left) {
            if (IsLeaf(Left)) {
                ASSERT(Left->PrimitiveCount == 1);
                int TreeletIndex = SortedPrims[Left->PrimitiveOffset].TriIndex;
                *Left = *Treelets[TreeletIndex].Root;
            } else {
                MergeUpperTreeAndLowerTrees(Left, SortedPrims, Treelets);
            }
        }

        if (bvh_node *Right = UpperNode->Right) {
            if (IsLeaf(Right)) {
                ASSERT(Right->PrimitiveCount == 1);
                int TreeletIndex = SortedPrims[Right->PrimitiveOffset].TriIndex;
                *Right = *Treelets[TreeletIndex].Root;
            } else {
                MergeUpperTreeAndLowerTrees(Right, SortedPrims, Treelets);
            }
        }
    } else {
        ASSERT(!"invalid codepath");
    }
}

internal bvh_node *
ConstructHlbvhTree(primitive *Prims, int Count) {
    bound TotalBound = DefaultBound();
    for (int i = 0; i < Count; ++i) {
        TotalBound = Union(TotalBound, Prims[i].Centroid);
    }

    int StepCount = (1 << 10) - 1;

    v3 TotalDim = TotalBound.Max - TotalBound.Min;
    v3 Step = {};
    Step.X = TotalDim.X / f32(StepCount);
    Step.Y = TotalDim.Y / f32(StepCount);
    Step.Z = TotalDim.Z / f32(StepCount);

    for (int i = 0; i < Count; ++i) {
        v3 CentroidOffset = Prims[i].Centroid - TotalBound.Min;

        u32 Steps[3] = {};
        for (int Kd = 0; Kd < 3; ++Kd) {
            Steps[Kd] = u32(CentroidOffset.Data[Kd] / Step.Data[Kd]);
            Steps[Kd] = Min(Max(0, Steps[Kd]), StepCount);
            assert((Steps[Kd] & StepCount) == Steps[Kd]);
        }

        Prims[i].Code = EncodeMorton3(Steps);
    }

    RadixSort(Prims, Count);

    bvh_treelet *Treelets = 0;
    int Begin = 0;
    const u32 HighBitMask = BITS(12) << 18;
    for (int I = 1; I < Count; ++I) {
        if ((Prims[Begin].Code & HighBitMask) != (Prims[I].Code & HighBitMask)) {
            bvh_treelet Treelet = {};
            Treelet.FirstPrimIndex = Begin;
            Treelet.Count = I - Begin;
            BufPush(Treelets, Treelet);

            Begin = I;
        }

        if (I == Count - 1) {
            bvh_treelet Treelet = {};
            Treelet.FirstPrimIndex = Begin;
            Treelet.Count = Count - Begin;
            BufPush(Treelets, Treelet);
        }
    }

    for (int I = 0; I < BufCount(Treelets); ++I) {
        bvh_treelet *Treelet = Treelets + I;
        Treelet->Root = EmitLBVH(Prims, Treelet->FirstPrimIndex, Treelet->Count, 17);
    }

    primitive *TreeletPrims = 0;
    for (int I = 0; I < BufCount(Treelets); ++I) {
        primitive Prim = {};
        Prim.TriIndex = I;
        Prim.Bound = Treelets[I].Root->Bound;
        Prim.Centroid = 0.5f * (Prim.Bound.Min + Prim.Bound.Max);
        BufPush(TreeletPrims, Prim);
    }

    bvh_node *UpperRoot = BuildUpperSah(TreeletPrims, 0, int(BufCount(Treelets)));
    MergeUpperTreeAndLowerTrees(UpperRoot, TreeletPrims, Treelets);

    BufFree(TreeletPrims);
    BufFree(Treelets);

    return UpperRoot;
}

internal int
CountNodes(bvh_node *Node)
{
    if (!Node) return 0;
    return 1 + CountNodes(Node->Left) + CountNodes(Node->Right);
}

internal void
BVHFlatten(bvh_node *Node, bvh_entry *Array, int *Offset)
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
        BVHFlatten(Node->Left, Array, Offset);
        Array[CurrIndex].SecondChildOffset = *Offset;
        BVHFlatten(Node->Right, Array, Offset);
    }
    else
    {
        Array[CurrIndex].PrimitiveOffset = Node->PrimitiveOffset;
    }
}

internal void
BVHFreeTree(bvh_node *Node)
{
    if (!Node) return;
    
    BVHFreeTree(Node->Left);
    BVHFreeTree(Node->Right);
    free(Node);
}

internal bvh_entry *
ConstructBVH(triangle *Triangles, bool FastBuild)
{
    bvh_entry *BVH = 0;
 
    primitive *Prims = BufInit(BufCount(Triangles), primitive);
    for (int PrimIndex = 0; PrimIndex < BufCount(Triangles); ++PrimIndex)
    {
        primitive *Prim = Prims + PrimIndex;
        Prim->TriIndex = PrimIndex;
        Prim->Bound = BoundTriangle(Triangles[PrimIndex]);
        Prim->Centroid = 0.5f * Prim->Bound.Min + 0.5f * Prim->Bound.Max;
    }
    bvh_node *Root = FastBuild? ConstructHlbvhTree(Prims, (int)BufCount(Triangles)): ConstructBVHTree(Prims, 0, (int)BufCount(Triangles));
    
    //NOTE(chen): flatten BVH
    BVH = BufInit(CountNodes(Root), bvh_entry);
    int Offset = 0;
    BVHFlatten(Root, BVH, &Offset);
    
    //NOTE(chen): resort triangles to match order of primitives
    triangle *SortedTriangles = BufInit(BufCount(Triangles), triangle);
    for (int PrimIndex = 0; PrimIndex < BufCount(Triangles); ++PrimIndex)
    {
        int SortedIndex = Prims[PrimIndex].TriIndex;
        SortedTriangles[PrimIndex] = Triangles[SortedIndex];
    }
    for (int TriIndex = 0; TriIndex < BufCount(Triangles); ++TriIndex)
    {
        Triangles[TriIndex] = SortedTriangles[TriIndex];
    }
    
    BufFree(SortedTriangles);
    BufFree(Prims);
    
    return BVH;
}
