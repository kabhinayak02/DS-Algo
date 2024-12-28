/*
GFG link: https://www.geeksforgeeks.org/problems/range-minimum-query/1

tc: o(q.log(n))
sc: o(4*n)
*/

void buildSegemntTree(int i, int l, int r, int segmentTree[], int arr[]){
    if(l == r){
        segmentTree[i] = arr[l];
        return;
    }
    
    int mid = l + (r-l)/2;
    buildSegemntTree(2*i+1, l, mid, segmentTree, arr);
    buildSegemntTree(2*i+2, mid+1, r, segmentTree, arr);
    
    segmentTree[i] = min(segmentTree[2*i+1], segmentTree[2*i+2]);
}
/* The functions which 
builds the segment tree */
int *constructST(int arr[],int n)
{
    int *segmentTree = new int[4*n];
    buildSegemntTree(0, 0, n-1, segmentTree, arr);
    return segmentTree;
}

int Query(int start, int end, int i, int l, int r, int st[]){
    if(l > end || r < start){
        return INT_MAX;
    }
    if(l >= start && r <= end){
        return st[i];
    }
    int mid = l + (r-l)/2;
    return min(Query(start, end, 2*i+1, l, mid, st), Query(start, end, 2*i+2, mid+1, r, st));
}
/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
    return Query(a, b, 0, 0, n-1, st);
}