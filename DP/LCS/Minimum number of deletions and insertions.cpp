/*
Problem Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1


Recursion + memoisation

tc: o(n*m)
sc: o(n*m)
*/
class Solution{
	public:
	int solve(int i, int j, string s1, string s2, vector<vector<int>>& dp){
	    if(i < 0 || j < 0) return 0;
	    
	    if(dp[i][j] != -1) return dp[i][j];
	    
	    if(s1[i] == s2[j]){
	        return dp[i][j] = 1 + solve(i-1, j-1, s1, s2, dp);
	    }
	    
	    return dp[i][j] = max({solve(i, j-1, s1, s2, dp), solve(i-1, j, s1, s2, dp)});
	}
	int minOperations(string str1, string str2) 
	{ 
	    int n = str1.size(), m = str2.size();
	    vector<vector<int>> dp(n, vector<int> (m, -1));
	    int len = solve(n-1, m-1, str1, str2, dp);
	    return n+m - 2*len;
	} 
};

/*
Bottom - UP 

tc: o(n*m)
sc: o(n*m)
*/
int minOperations(string str1, string str2) 
{ 
    int n = str1.size(), m = str2.size();
    
    // Initialize DP table with size (n+1) x (m+1)
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    // LCS length
    int len = dp[n][m];
    
    // Minimum operations required
    return n + m - 2 * len;
}


/*
Bottom - UP: Space optimisation 

tc: o(n*m)
sc: o(m)
*/
int minOperations(string str1, string str2) 
{ 
    int n = str1.size(), m = str2.size();
    
    // Use two 1D arrays of size m+1 to store only the current and previous row
    vector<int> prev(m+1, 0), curr(m+1, 0);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(str1[i-1] == str2[j-1]){
                curr[j] = 1 + prev[j-1];
            } else {
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        // Move the current row to previous and reset current for the next iteration
        prev = curr;
    }
    
    // LCS length is stored in curr[m] after the last iteration
    int len = curr[m];
    
    // Minimum operations required
    return n + m - 2 * len;
}
