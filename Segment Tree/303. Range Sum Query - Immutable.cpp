/*
using segment tree

sc: o(q.logn)
sc: o(n)
*/
class NumArray {
public: 
    vector<int> segmentTree;
    int n;
    void buildSegmentTree(int i, int l, int r, vector<int>& nums){
        if(l == r){
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r-l)/2;
        buildSegmentTree(2*i+1, l, mid, nums);
        buildSegmentTree(2*i+2, mid+1, r, nums);

        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4*n, 0);
        buildSegmentTree(0, 0, n-1, nums);
    }
    int Query(int start, int end, int i, int l, int r){
        if(end < l || start > r){
            return 0;
        }
        if(start <= l && r <= end){
            return segmentTree[i];
        }
        int mid = l + (r-l)/2;
        return Query(start, end, 2*i+1, l, mid) + Query(start, end, 2*i+2, mid+1, r);
    }
    int sumRange(int left, int right) {
        return Query(left, right, 0, 0, n-1);
    }
};
