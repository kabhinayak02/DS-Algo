/*
Top Down Approach 

tc: o(n*m)
sc: o(n*m)
*/
class Solution {
public:
    int n, m;
    bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(j == m) return i == n;

        if(dp[i][j] != -1) return dp[i][j];

        bool match = (i < n) && (s[i] == p[j] || p[j] == '.');
        bool ans = 0;
        if(j + 1 < m && p[j+1] == '*'){
            bool skipIt = solve(i, j+2, s, p, dp);
            bool takeIt = (match && solve(i+1, j, s, p, dp));

            ans = takeIt || skipIt;
        }
        else{ // s[i] == p[j] and next char is not '*'. so, curr char is not the part of '*'.
            ans = match && solve(i+1, j+1, s, p, dp); 
        } 
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        n = s.length(), m = p.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        return solve(0, 0, s, p, dp);
    }
};

/*
Convert Above Top down to bottom up approach 
*/
bool isMatch(string s, string p) {
    int n = s.length(), m = p.length();
    
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

    dp[n][m] = true;  // Base case: both strings are fully matched.

    for (int i = n; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {  // Loop till j = 0
            bool match = (i < n) && (s[i] == p[j] || p[j] == '.');
            if (j + 1 < m && p[j+1] == '*') {
                bool skipIt = dp[i][j+2];  // Skip '*' and the preceding element.
                bool takeIt = (match && dp[i+1][j]);  // Use '*' to match more of the preceding character.
                dp[i][j] = takeIt || skipIt;
            } else {
                dp[i][j] = match && dp[i+1][j+1];  // Regular character match.
            }
        }
    }
    
    return dp[0][0];  // Return the final answer after the DP table is filled.
}

/*
Space Optimised 
tc: o(n*m)
sc: o(m)
*/



/*
Bottom - Up (0, 0 -> n, m)

*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();

        vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));
        dp[0][0] = true;

        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(p[j-1] == '.' || p[j-1] == s[i-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2];
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        return dp[n][m];

    }
};
