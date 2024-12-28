/*
GFG link: https://www.geeksforgeeks.org/problems/sum-of-query-ii5310/1

tc: o(q.log(n))
sc: o(4*n)
*/
class Solution{
public:
    void buildSegmentTree(int i, int l, int r, int arr[], vector<int>& segmentTree){
        if(l == r){
            segmentTree[i] = arr[l];
            return;
        }
        
        int mid = l + (r-l)/2;
        buildSegmentTree(2*i+1, l, mid, arr, segmentTree);
        buildSegmentTree(2*i+2, mid+1, r, arr, segmentTree);
        
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }
    int Query(int i, int start, int end, int l, int r, vector<int>& segmentTree){
        if(l > end || r < start){
            return 0;
        }
        if(l >= start && r <= end){
            return segmentTree[i];
        }
        
        int mid = l+(r-l)/2;
        return Query(2*i+1, start, end, l, mid, segmentTree) + Query(2*i+2, start, end, mid+1, r, segmentTree);
    }
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        vector<int> segmentTree(4*n);
        
        buildSegmentTree(0, 0, n-1, arr, segmentTree);
        
        vector<int> ans;
        for(int i=0; i<2*q; i+=2){
            int start = queries[i] - 1;
            int end = queries[i+1] - 1;
            
            ans.push_back(Query(0, start, end, 0, n-1, segmentTree));
        }
        return ans;
    }
};