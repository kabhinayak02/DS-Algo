/*

tc: o(m.m.n)
sc: o(n)
observation based problem 
*/
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int maxRow = 0;
        for(auto &currRow : matrix){
            vector<int> inverted(n);

            for(int col=0; col<n; col++){
                inverted[col] = 1 - currRow[col];
            }

            int count = 0;
            for(auto &row: matrix){
                if(row == inverted || row == currRow){
                    count++;
                }
            }
            maxRow = max(maxRow, count);
        }
        return maxRow;
    }
};