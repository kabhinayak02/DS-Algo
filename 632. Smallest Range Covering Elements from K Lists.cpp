/*
using 

stores one element from each list in a array of min heap, because min and max of element from that array gives the
range where element from each list is in that range as an answer. but using min heap instead of array improves the time complexity
also we need to stores the index of element and group no. in min heap. 
tc: o(nlogn)
sc: o(k)
*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int maxEle = INT_MIN;

        for(int i=0; i<k; i++){
            pq.push({nums[i][0], i, 0});
            maxEle = max(maxEle, nums[i][0]);
        }

        vector<int> ansRange = {-1000000, 1000000};

        while(!pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();

            int minEle = curr[0];
            int listIdx = curr[1];
            int idx = curr[2];

            if(maxEle - minEle < ansRange[1] - ansRange[0]){
                ansRange[0] = minEle;
                ansRange[1] = maxEle;
            }
           
            if(idx + 1 < nums[listIdx].size()){
                int nextEle = nums[listIdx][idx+1];
                pq.push({nextEle, listIdx, idx+1});
                maxEle = max(maxEle, nextEle);
            }
            else{
                break;
            }
        }
        return ansRange;
    }
};