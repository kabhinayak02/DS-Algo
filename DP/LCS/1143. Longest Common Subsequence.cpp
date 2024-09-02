
/*
Recursion + Memiosation

tc: o(n*m)
sc: o(n*m)
*/
class Solution {
public:
    int solve(int i, int j, const string &text1, const string &text2, vector<vector<int>>& dp){
        if(i < 0 || j < 0 ) return 0;
 
        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + solve(i-1, j-1, text1, text2, dp);
        } else {
            return dp[i][j] = max(solve(i-1, j, text1, text2, dp), solve(i, j-1, text1, text2, dp));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int> (m, -1));
    
        return solve(n-1, m-1, text1, text2, dp);
    }
};


/*
tabulation 

tc: o(m*n)
sc: o(m*n)
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

/*
Bottom Up: Space optimised

tc: o(n*m)
sc: o(n)
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        
        // Two 1D arrays to store the current and previous row results
        vector<int> prev(n+1, 0), curr(n+1, 0);

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1[i-1] == text2[j-1]) {
                    curr[j] = 1 + prev[j-1];
                } else {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            // Swap current and previous for the next iteration
            prev = curr;
        }
        
        return prev[n];  // The LCS length is in the last element of the prev array
    }
};
