// Recursion + Memoisation 
// tc: o(n*m)
// sc: o(n*m)
class Solution {
public:
    int dp[1001][1001];
    int solve(int i, int j, string text1, string text2){
        // base case 
        if(i >= text1.size() || j >= text2.size()) return 0;
 
        if(dp[i][j] != -1) return dp[i][j];

        // choice diagram 
        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + solve(i+1, j+1, text1, text2);
        }
        else{
            return dp[i][j] = max(solve(i+1, j, text1, text2), solve(i, j+1, text1, text2));
        }

    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, text1, text2);
    }
};

// Bottom - UP 
// tc: o(n*m)
// sc: o(n*m)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        
        // base case 
        for(int i=0; i<m+1; i++){
            dp[i][0] = 0;
        }
        for(int j=0; j<n+1; j++){
            dp[0][j] = 0;
        }

        // choice diagram
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