/*
[TLE Solution]: Brute force (Recursive based solution)

tc: o(n^n)
sc: o(n) recursive stack 
*/
class Solution {
public:
    int solve(int ind, int jumps, vector<int>& nums){
        if(ind >= nums.size()-1) return jumps;  // Base case: if you've reached or crossed the last index, return jumps

        int mini = INT_MAX;
        for(int i = 1; i <= nums[ind]; i++){    // Start i from 1 to avoid revisiting the same index
            if(ind + i < nums.size()) {         // Ensure you are within bounds
                mini = min(mini, solve(ind + i, jumps + 1, nums));
            }
        }
        return mini;
    }
    int jump(vector<int>& nums) {
        return solve(0, 0, nums);   // Start solving from index 0 with 0 jumps initially
    }
};


/*
[TLE Solution]: DP Approach: Recursion + Memoisation

tc: o(n^2)
sc: o(n^2)
*/
class Solution {
public:
    int solve(int ind, int jumps, vector<int>& nums, vector<vector<int>> &t){
        if(ind >= nums.size()-1) return jumps;  // Base case: if you've reached or crossed the last index, return jumps


        if(t[ind][jumps] != -1) return t[ind][jumps];

        int mini = INT_MAX;
        for(int i = 1; i <= nums[ind]; i++){    // Start i from 1 to avoid revisiting the same index
            if(ind + i < nums.size()) {         // Ensure you are within bounds
                mini = min(mini, solve(ind + i, jumps + 1, nums, t));
            }
        }
        return t[ind][jumps] = mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> t(n, vector<int> (n, -1));
        return solve(0, 0, nums, t);   // Start solving from index 0 with 0 jumps initially
    }
};

/*
[Accepted]: Greedy Approach (Range based solution)

tc: o(n
sc: o(1)
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, jumps = 0;

        while(r < n-1){
            int farthest = 0;
            for(int i=l; i<=r; i++){
                farthest = max(farthest, i+nums[i]);
            }
            jumps++;
            l = r+1;
            r = farthest;
        }
        
        return jumps;
    }
};