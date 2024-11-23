/*

tc: o(n.m)
sc: o(n.m)
*/
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> mat(m, vector<int>(n, 0));

        // Mark walls as 1
        for (vector<int> &wall : walls) {
            mat[wall[0]][wall[1]] = 1;
        }
        // Mark guards as 2
        for (vector<int> &guard : guards) {
            mat[guard[0]][guard[1]] = 2;
        }

        // Guard the cells
        for (vector<int> &guard : guards) {
            int x = guard[0], y = guard[1];

            // Up
            for (int i = x - 1; i >= 0; i--) {
                if (mat[i][y] == 1 || mat[i][y] == 2) break;
                mat[i][y] = 3; // Guarded cell
            }

            // Down
            for (int i = x + 1; i < m; i++) {
                if (mat[i][y] == 1 || mat[i][y] == 2) break;
                mat[i][y] = 3; // Guarded cell
            }

            // Left
            for (int i = y - 1; i >= 0; i--) {
                if (mat[x][i] == 1 || mat[x][i] == 2) break;
                mat[x][i] = 3; // Guarded cell
            }

            // Right
            for (int i = y + 1; i < n; i++) {
                if (mat[x][i] == 1 || mat[x][i] == 2) break;
                mat[x][i] = 3; // Guarded cell
            }
        }

        // Count unguarded cells
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) cnt++; // Unguarded cells
            }
        }
        return cnt;
    }
};