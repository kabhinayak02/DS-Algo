/*
Brute Force

tc: o(n*m)
sc: o(n*m)
*/
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n != original.size()) return {}; 
        vector<vector<int>> ans(m, vector<int> (n, 0));

        int idx = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans[i][j] = original[idx];
                idx++;
            }
        }
        return ans;
    }
};

/*

tc: o(original.size())
sc: o(n*m)
*/
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n != original.size()) return {}; 
        vector<vector<int>> ans(m, vector<int> (n, 0));

        for(int i=0; i<original.size(); i++){
            int row = i/n;
            int col = i%n;
            ans[row][col] = original[i];
        }
        return ans;
    }
};