/*
top down approach 

tc: o(n*m)
sc: o(n*m) for dp array + o(n+m) for recursion stack 

*/
class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& dp){
        // Base case
        if(i == m-1 && j == n-1){
            return 1;
        }
        if (i >= m || j >= n) {
            return 0;
        }

        // memoisation 
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // conditions 
        int right = solve(i, j+1, m, n, dp);
        int down = solve(i+1, j, m, n, dp);

        // return 
        return dp[i][j] = right + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
    }
};
/*
bottom - up approach 

tc: o(n*m)
sc: o(n*m)
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m, vector<int>(n, 0));
        t[0][0] = 1; // assumption as one test case found in the question 

        for(int col = 1; col<n; col++){
            t[0][col] = 1;
        }
        for(int row = 1; row<m; row++){
            t[row][0] = 1;
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                t[i][j] = t[i-1][j] + t[i][j-1]; 
            }
        }
        return t[m-1][n-1];
    }
};