/*
Using Dp with bitwise Approach

tc: O(n^2 * 2^n * log10^6)
sc: O(2^n)
*/
class Solution {
public:
    int solve(int op, int mask, vector<int>& nums, vector<int>& dp){
        int n = nums.size(), m = nums.size()/2;
        if(op > m) return 0;

        if(dp[mask] != -1) return dp[mask];

        int maxScore = 0;

        for(int i=0; i<n; i++){
            if((mask & (1<<i))) continue;
            for(int j=0; j<n; j++){
                if(mask & (1<<j) || i == j) continue;
                int newMask = (1<<i) | (1<<j) | mask;
                int score = op * __gcd(nums[i], nums[j]) + solve(op+1, newMask, nums, dp);
                maxScore = max(maxScore, score);
            }
        }
        return dp[mask] = maxScore;
    }
    int maxScore(vector<int>& nums) {
        vector<int> dp(1 << 14, -1);
        return solve(1, 0, nums, dp);
    }
};

/*
Using Dp with bitwise Approach

tc: O(n^2 * 2^n * log10^6)
sc: O(2^n)
*/
class Solution {
public:
    int solve(int op, int mask, vector<int>& nums, vector<int>& dp){
        int n = nums.size(), m = nums.size()/2;
        if(op > m) return 0;

        if(dp[mask] != -1) return dp[mask];

        for(int i=0; i<n; i++){
            if((mask & (1<<i))) continue;
            for(int j=i+1; j<n; j++){
                if(mask & (1<<j)) continue;
                int newMask = (1<<i) | (1<<j) | mask;
                int score = op * __gcd(nums[i], nums[j]) + solve(op+1, newMask, nums, dp);
                dp[mask] = max(dp[mask], score);
            }
        }
        return dp[mask];
    }
    int maxScore(vector<int>& nums) {
        vector<int> dp(1 << 14, -1);
        return solve(1, 0, nums, dp);
    }
};


/*

We have precomputed the gcd in 2d array 
tc: O(n^2 * 2^n)
sc: o(m*2)
*/
class Solution {
public:
    int func(vector<int>& nums, int op, int mask, vector<int>& dp, vector<vector<int>>& gcd){
        int m = nums.size(), n = nums.size()/2;
        if(op > n) return 0;
        if(dp[mask] != -1) return dp[mask];

        for(int i=0;i<m;i++){
            if( (mask & (1<<i)) ) continue;
            for(int j=i+1;j<m;j++){
                if( (mask & (1<<j)) ) continue;
                
                int newMask = (1<<i) | (1<<j) | mask;
                int score = op * gcd[i][j] + func(nums, op+1, newMask, dp, gcd);
                dp[mask] = max(dp[mask], score);
            }
        }
        return dp[mask];
    }

    int maxScore(vector<int>& nums) {
        vector<int> dp(1<<14, -1);

        int m = nums.size(), n = nums.size()/2;
        vector<vector<int>> gcd(m, vector<int>(m, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                gcd[i][j] = __gcd(nums[i], nums[j]);
            }
        }

        return func(nums, 1, 0, dp, gcd);
    }
};