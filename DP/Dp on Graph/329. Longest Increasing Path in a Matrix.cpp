
// Brute force 
class Solution {
public:
    int solve(vector<vector<int>> &matrix, int i, int j){
        int n = matrix.size(), m = matrix[0].size();
        int maxLen = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};
        for(int k=0; k<4; k++){
            int newRow = i + delRow[k];
            int newCol = j + delCol[k];

            if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && matrix[newRow][newCol] < matrix[i][j]){
                maxLen = max(maxLen, 1 + solve(matrix, newRow, newCol));
            }
        }
        return maxLen;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(); // row
        int m = matrix[0].size(); // col 
        int maxPath = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                maxPath = max(maxPath, solve(matrix, i, j));
            }
        }
        return maxPath;
    }
};



// Using DP (Memoisation)
class Solution {
public:
    int t[201][201];
    int solve(vector<vector<int>> &matrix, int i, int j){
        int n = matrix.size(), m = matrix[0].size();
        int maxLen = 1;
        
        if(t[i][j] != -1) return t[i][j];

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};

        for(int k=0; k<4; k++){
            int newRow = i + delRow[k];
            int newCol = j + delCol[k];

            if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && matrix[newRow][newCol] < matrix[i][j]){
                maxLen = max(maxLen, 1 + solve(matrix, newRow, newCol));
            }
        }
        return t[i][j] = maxLen;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(); // row
        int m = matrix[0].size(); // col 
        memset(t, -1, sizeof(t));

        int maxPath = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                maxPath = max(maxPath, solve(matrix, i, j));
            }
        }
        return maxPath;
    }
};