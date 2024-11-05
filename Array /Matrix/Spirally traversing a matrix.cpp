/*
gfg Link: 
Same question as Leetcode 54

tc: o(n.m)
sc: o(1)
*/

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans;
        
        int i = 0, j = 0;
        int max_row = matrix.size() - 1, max_col = matrix[0].size() - 1;

        while (i <= max_row && j <= max_col) {
            // Traverse from left to right
            for (int col = j; col <= max_col; col++) {
                ans.push_back(matrix[i][col]);
            }
            i++;
            
            // Traverse from top to bottom
            for (int row = i; row <= max_row; row++) {
                ans.push_back(matrix[row][max_col]);
            }
            max_col--;
            
            // Traverse from right to left
            if (i <= max_row) {
                for (int col = max_col; col >= j; col--) {
                    ans.push_back(matrix[max_row][col]);
                }
                max_row--;
            }
            
            // Traverse from bottom to top
            if (j <= max_col) {
                for (int row = max_row; row >= i; row--) {
                    ans.push_back(matrix[row][j]);
                }
                j++;
            }
        }
    }
};