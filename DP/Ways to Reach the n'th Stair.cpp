/*
Gfg Link: https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1
Using Recursion + Memoisation

tc: o(n)
sc: o(n)
*/
class Solution
{
    public:
    int mod = 1e9+7;
    int solve(int n, vector<int>& dp){
        if(n == 1 || n == 2) return n;
        
        if(dp[n] != -1) return dp[n];
        
        int one_step = solve(n-1, dp);
        int two_step = solve(n-2, dp);
        
        return dp[n] = (one_step%mod + two_step%mod)%mod;
    }
    int countWays(int n)
    {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};

/*
Bottom up 

tc: o(n)
sc: o(n)
*/

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int mod = 1e9+7;
    int countWays(int n)
    {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = (dp[i-1]%mod + dp[i-2]%mod)%mod;
        }
        return dp[n];
    }
};