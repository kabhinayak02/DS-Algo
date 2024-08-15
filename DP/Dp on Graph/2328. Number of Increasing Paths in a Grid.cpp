// Recursion + Memoisation
// tc: o(n*m)
// sc: o(n*m)
class Solution {
public:
    int n, m;
    int mod = 1000000007;
    int t[1001][1001];
    int solve(vector<vector<int>> &grid, int i, int j){

        if(t[i][j] != -1) return t[i][j];

        long long maxLen = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for(int k=0; k<4; k++){
            int newRow = i + delRow[k];
            int newCol = j + delCol[k];

            if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && grid[newRow][newCol] > grid[i][j]){
                maxLen = (maxLen%mod + solve(grid, newRow, newCol)%mod)%mod;
            }
        }
        return t[i][j] = maxLen;
    }
    int countPaths(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(t, -1, sizeof(t));
        
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                count = (count%mod + solve(grid, i, j)%mod)%mod;
            }
        }
        return count;
    }
};