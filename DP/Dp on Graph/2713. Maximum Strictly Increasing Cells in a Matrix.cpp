
// Dp (gives TLE) -> need more optimised 
// tc: o(n.m.max(n+m))
// sc: o(n.m)
class Solution {
public:
    int n, m;
    int solve(vector<vector<int>> &mat, int row, int col,  vector<vector<int>> &dp){
        int len = 1;

        if(dp[row][col] != -1) return dp[row][col];

        for(int i=0; i<m; i++){
            if(mat[row][i] > mat[row][col]){
                len = max(len, 1 + solve(mat, row, i, dp));
            }
        }
        for(int i=0; i<n; i++){
            if(mat[i][col] > mat[row][col]){
                len = max(len, 1 + solve(mat, i, col, dp));
            }
        }
        return dp[row][col] = len;
    }
    int maxIncreasingCells(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));

        int maxPath = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                maxPath = max(maxPath, solve(mat, i, j, dp));
            }
        }
        return maxPath;
    }
};