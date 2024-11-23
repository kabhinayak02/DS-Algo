/*
using matrix traversing 

tc: o(n.m)
sc: o(n.m)
*/
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(); // row
        int n = box[0].size(); // col
        vector<vector<char>> ans(n, vector<char> (m, '.'));
        int ansRow = 0;
        int ansCol = 0;
        for(int i=0; i<m; i++){
            int idx = n-1;
            for(int j=n-1; j>=0; j--){
                if(box[i][j] == '#'){
                    ans[idx][m-i-1] = '#';
                    idx--; 
                }
                if(box[i][j] == '*'){
                    ans[j][m-i-1] = '*';
                    idx = j-1;
                }
            }
        }
        return ans;
    }
};