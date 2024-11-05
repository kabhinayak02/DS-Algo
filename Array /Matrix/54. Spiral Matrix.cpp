/*
matrix traversal 

use 4 pointer 

tc: o(n*m)
sc: o(1)
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int dir = 0;
        
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = m-1;

        /*  
        dir = 0 -> left to right
        dir = 1 -> top to bottom
        dir = 2 -> right to left
        dir = 3 -> bottom to top 
        */
        vector<int> ans;

        while(ans.size() < (m*n)){
            if(dir == 0){
                // left to right
                // constant : top
                for(int i=left; i<=right; i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            if(dir == 1){
                // top to bottom
                // constant : right
                for(int i=top; i<=bottom; i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            if(dir == 2){
                // right to left
                // constant : bottom
                for(int i=right; i>=left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(dir == 3){
                // bottom to top
                // constant : left
                for(int i=bottom; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            dir += 1;
            if(dir == 4) dir = 0;
            //dir = (dir + 1) % 4; //can use this too 
        }
        return ans;
    }
};