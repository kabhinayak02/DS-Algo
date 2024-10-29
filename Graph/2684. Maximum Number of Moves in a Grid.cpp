/*
using memoisation and dfs

tc: o(n.m)
sc: o(n.m)
*/

class Solution {
public:
    int n, m;
    vector<int> directions = {-1, 0, 1};
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(dp[row][col] != -1) return dp[row][col];
        int moves = 0;
        for(int &dir: directions){
            int nrow = row + dir;
            int ncol = col + 1;

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[row][col] < grid[nrow][ncol]){
                moves = max(moves, dfs(nrow, ncol, grid, dp) + 1);
            }
        }
        return dp[row][col] = moves;
    }
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, dfs(i, 0, grid, dp));
        }
        return ans;
    }
};