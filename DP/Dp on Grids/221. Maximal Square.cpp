/*
using top-down approach 

tc: o(n.m)
sc: o(n.m + n+m)
*/
class Solution {
public:
    int solve(int i, int j, int& maxAns, vector<vector<char>>& mat, vector<vector<int>>& dp){
        if(i >= mat.size() || j >= mat[0].size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int left = solve(i, j+1, maxAns, mat, dp);
        int down = solve(i+1, j, maxAns, mat, dp);
        int dia = solve(i+1, j+1, maxAns, mat, dp);

        if(mat[i][j] == '1'){
            dp[i][j] = 1 + min({left, down, dia});
            maxAns = max(maxAns, dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j] = 0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int maxAns = 0;
        solve(0, 0, maxAns, matrix, dp);
        return maxAns*maxAns; // return area as an answer
    }
};

/*
bottom-up approach 

tc: o(n.m)
sc: o(n.m)
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxAns = 0;
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int left = dp[i][j+1];
                int down = dp[i+1][j];
                int dia = dp[i+1][j+1];

                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min({left, down, dia});
                    maxAns = max(maxAns, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return maxAns*maxAns; // area
    }
};

/*
Space optimisation 

tc: o(n.m)
sc: o(2m)
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxAns = 0;

        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int left = curr[j+1];
                int down = next[j];
                int dia = next[j+1];

                if(matrix[i][j] == '1'){
                    curr[j] = 1 + min({left, down, dia});
                    maxAns = max(maxAns, curr[j]);
                }
                else{
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        return maxAns*maxAns; // area
    }
};