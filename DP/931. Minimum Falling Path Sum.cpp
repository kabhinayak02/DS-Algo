
// tc: o(n*m)
// sc: o(m)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(); // row  
        int m = matrix[0].size(); // col

        vector<int> prev(m, 0);
        for(int i=0; i<m; i++){
            prev[i] = matrix[0][i];
        }

        for(int i=1; i<n; i++){
            vector<int> curr(m, 0);
            for(int j=0; j<m; j++){
                if(j == 0){
                    curr[j] = matrix[i][j] + min(prev[j], prev[j+1]);
                }
                else if(j == m-1){
                    curr[j] = matrix[i][j] + min(prev[j], prev[j-1]);
                }
                else{
                    curr[j] = matrix[i][j] + min({prev[j], prev[j+1], prev[j-1]});
                }
            }
            prev = curr;
        }
        for(int i=0; i<m; i++){
            cout << prev[i] << " ";
        }
        return *min_element(prev.begin(), prev.end());
    }
};