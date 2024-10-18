/*
using backtracking

Bitwise-OR of all the element in array gives maximum OR. Find it first and compare it with all the possible subsets's bitwise-OR
create all the possible subsets using backtracking and check of the maxOr as a base case
tc: o(2^n)
*/
class Solution {
public:
    int solve(int idx, int currOr, int maxOr, vector<int>& nums){
        if(idx == nums.size()){
            if(currOr == maxOr){
                return 1;
            }
            return 0;
        }

        int take = solve(idx+1, currOr | nums[idx], maxOr, nums);
        int notTake = solve(idx+1, currOr, maxOr, nums);

        return take + notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int &num: nums){
            maxOr |= num;
        }
        
        int currOr = 0;
        return solve(0, currOr, maxOr, nums);
    }
};

/*
using rescursion memoisation 

tc: o(n*maxOr)
sc: o(n*maxOr);
*/
class Solution {
public:
    int solve(int idx, int currOr, int maxOr, vector<int>& nums, vector<vector<int>>& t){
        if(idx == nums.size()){
            if(currOr == maxOr){
                return 1;
            }
            return 0;
        }
        if(t[idx][currOr] != -1) return t[idx][currOr];

        int take = solve(idx+1, currOr | nums[idx], maxOr, nums, t);
        int notTake = solve(idx+1, currOr, maxOr, nums, t);

        return t[idx][currOr] = take + notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int &num: nums){
            maxOr |= num;
        }

        int n = nums.size();
        vector<vector<int>> t(n+1, vector<int>(maxOr+1, -1));
        
        int currOr = 0;
        return solve(0, currOr, maxOr, nums, t);
    }
};