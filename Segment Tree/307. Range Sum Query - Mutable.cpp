/*
using segment tree

tc: o(log(n))
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
    void updateQuery(int i, int l, int r, int index, int val){
        if(index < l || index > r){
            return;
        }
        if(l == r){
            if(l == index){
                segmentTree[i] = val;
            }
            return;
        }
        int mid = l + (r-l)/2;
        updateQuery(2*i+1, l, mid, index, val);
        updateQuery(2*i+2, mid+1, r, index, val);
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }
    void update(int index, int val) {
        updateQuery(0, 0, n-1, index, val);
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
    void updateSegmentTree(int i, int l, int r, int index, int val){
        if(l == r){
            segmentTree[i] = val;
            return;
        }
        int mid = l + (r-l)/2;
        if(index <= mid){
            updateSegmentTree(2*i+1, l, mid, index, val);
        }
        else{
            updateSegmentTree(2*i+2, mid+1, r, index, val);
        }
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }
    void update(int index, int val) {
        updateSegmentTree(0, 0, n-1, index, val);
    }
    int querySegmentTree(int start, int end, int i, int l, int r){
        if(end < l || start > r){
            return 0;
        }
        if(start <= l && r <= end){
            return segmentTree[i];
        }
        int mid = l + (r-l)/2;
        return querySegmentTree(start, end, 2*i+1, l, mid) + querySegmentTree(start, end, 2*i+2, mid+1, r);
    }
    int sumRange(int left, int right) {
        return querySegmentTree(left, right, 0, 0, n-1);
    }
};