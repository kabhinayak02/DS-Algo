
/*
Gfg Link: https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter5639/1

tc: o(n)
sc: o(n), recursive stack space
*/
class Solution{
	public:
	    int solve(int ind, int n, vector<int>& dp){
	        if(ind >= n-1) return 1;
	        
	        if(dp[ind] != -1) return dp[ind];
	        
	        return dp[ind] = 1 + min(solve(ind+1, n, dp), solve(ind+2, n, dp));
	    }
		int nthStair(int n){
		    vector<int> t(n+1, -1);
		    return solve(0, n, t);
		}
};