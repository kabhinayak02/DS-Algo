#include <vector>
#include <unordered_map>
using namespace std;

// Recursion + Memoisation
// tc: o(n*m)
// sc: o(n*m)

class Solution {
public:
    int m, n;
    int t[101][101];
    int solve(int i, int j, vector<vector<int>> &grid){
        if(i == m-1 && j == n-1 && grid[i][j] != 1) return 1;
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 1) return 0;

        if(t[i][j] != -1) return t[i][j];

        int right = solve(i, j+1, grid);
        int down = solve(i+1, j, grid);

        return t[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size(), n = obstacleGrid[0].size();
        memset(t, -1, sizeof(t));
        return solve(0, 0, obstacleGrid);
    }
};