#include <vector>
#include <unordered_map>
using namespace std;


// Recursion + Memoisation
// tc: o(n^2)
// sc: o(n^2)
class Solution {
public:
    int n;
    int dp[2501][2501];
    int solve(int idx, int p, vector<int>& nums){
        if(idx >= n) return 0;

        if(dp[idx][p+1] != -1) return dp[idx][p+1];

        int take = 0;
        if(p == -1 || nums[p] < nums[idx]){
            take = 1 + solve(idx+1, idx, nums);
        }
        int notTake = solve(idx+1, p, nums);
        
        return dp[idx][p+1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, nums);
    }
};


// Bottom Up (Space optimised)
// tc: o(n^2)
// sc: o(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int maxLen = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                    maxLen = max(maxLen, dp[i]);
                }
            }
        }
        return maxLen;
    }
};