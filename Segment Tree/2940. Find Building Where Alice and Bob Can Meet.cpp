/*
using segment tree

tc: o(nlogn + qlogn) // not sure
sc: o(n + q)
*/
class Solution {
public:
    void buildSegmentTree(int i, int l, int r, vector<int>& heights, int segmentTree[]){
        if(l == r){
            segmentTree[i] = l; // storing the index
            return;
        }

        int mid = l + (r-l)/2;
        buildSegmentTree(2*i+1, l, mid, heights, segmentTree);
        buildSegmentTree(2*i+2, mid+1, r, heights, segmentTree);

        int leftIndex = segmentTree[2*i+1];
        int rightIndex = segmentTree[2*i+2];
        segmentTree[i] = (heights[leftIndex] > heights[rightIndex]) ? leftIndex : rightIndex;
    }
    int* constructST(vector<int>& heights, int n){
        int* segmentTree = new int[4*n];
        buildSegmentTree(0, 0, n-1, heights, segmentTree);
        return segmentTree;
    }
    int querySegmentTree(int start, int end, int i, int l, int r, int st[], vector<int>& heights){
        if(l > end || r < start){
            return -1; // invalid index
        }
        if(l >= start && r <= end){
            return st[i];
        }

        int mid = l + (r-l)/2;
        int leftIdx = querySegmentTree(start, end, 2*i+1, l, mid, st, heights);
        int rightIdx = querySegmentTree(start, end, 2*i+2, mid+1, r, st, heights);

        if(leftIdx == -1){
            return rightIdx;
        }
        if(rightIdx == -1){
            return leftIdx;
        }

        return heights[leftIdx] > heights[rightIdx] ? leftIdx : rightIdx;
        
    }
    int RMIQ(int segmentTree[], vector<int>& heights, int n, int start, int end){
        return querySegmentTree(start, end, 0, 0, n-1, segmentTree, heights);
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int* segmentTree = constructST(heights, n);

        vector<int> ans;
        for(auto& query: queries){
            int min_idx = min(query[0], query[1]);
            int max_idx = max(query[0], query[1]);

            if(min_idx == max_idx){
                ans.push_back(min_idx);
                continue;
            }
            else if(heights[max_idx] > heights[min_idx]){
                ans.push_back(max_idx);
                continue;
            }

            int l = max_idx + 1;
            int r = n-1;
            int ans_idx = INT_MAX;
            while(l <= r){
                int mid = l + (r-l)/2;
                int idx = RMIQ(segmentTree, heights, n, l, mid); // need index which is leftMost

                if(heights[idx] > max(heights[max_idx], heights[min_idx])){
                    ans_idx = min(ans_idx, idx); // try to find more leftMost possible ans
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            if(ans_idx == INT_MAX){
                ans.push_back(-1);
            }
            else{
                ans.push_back(ans_idx);
            }
        }
        return ans;
    }
};