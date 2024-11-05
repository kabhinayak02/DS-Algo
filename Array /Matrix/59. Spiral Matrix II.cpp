/*
matrix traversal 

using 4 pointer and Spiral matrix 1 Logic 

tc: o(n.n)
sc: o(n) return ans
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;

        int dir = 0;
        int cnt = 1;
        
        while(left <= right && top <= bottom){
            if(dir == 0){
                // left to right
                // constant : top (row)
                for(int i=left; i<=right; i++){
                    ans[top][i] = cnt;
                    cnt++;
                }
                top++;
            }
            if(dir == 1) {
                // top to bottom
                // constant : right
                for(int i=top; i<=bottom; i++){
                    ans[i][right] = cnt;
                    cnt++;
                }
                right--;
            }
            if(dir == 2){
                // right to left;
                // constant: bottom
                for(int i=right; i>=left; i--){
                    ans[bottom][i] = cnt;
                    cnt++;
                }
                bottom--;
            }
            if(dir == 3){
                // bottom to top
                // constant: left
                for(int i=bottom; i>=top; i--){
                    ans[i][left] = cnt;
                    cnt++;
                }   
                left++;
            }
            dir += 1;
            if(dir == 4) dir = 0;
        }
        return ans;
    }
};