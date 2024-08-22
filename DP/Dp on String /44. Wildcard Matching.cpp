
/*
Top - Down 
tc: o(n*m)
sc: o(n*m)
*/
class Solution {
public:
    bool solve(int i, int j, string& s, string& p, vector<vector<int>> &dp){
        if(i < 0 && j < 0) return true; // both the string are exhausted, return true

        if(i < 0 && j >= 0) return false; // Only p is exhausted, return false

        if(j < 0 && i >= 0) { // pattern is remaining and it has to '*' to return true
            for(int k=0; k<=i; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(p[i] == s[j] || p[i] == '?'){ // if both the char is same 
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        }

        if(p[i] == '*'){ // '*' can exhausted multiple char so need recursion to process all the possibilities 
            return dp[i][j] = solve(i-1, j, s, p, dp) || solve(i, j-1, s, p, dp);
        }

        return dp[i][j] = false;
    } 
    bool isMatch(string s, string p) {
        int n = p.length(), m = s.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));

        return solve(n-1, m-1, s, p, dp);
    }
};

/*
Convert to 1-based indexing 
*/
class Solution {
public:
    bool solve(int i, int j, string& s, string& p, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return true; // both the string are exhausted, return true

        if(i == 0 && j > 0) return false; // Only p is exhausted, return false

        if(j == 0 && i > 0) { // pattern is remaining and it has to '*' to return true
            for(int k=1; k<=i; k++){
                if(p[k-1] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(p[i-1] == s[j-1] || p[i-1] == '?'){ // if both the char is same 
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        }

        else if(p[i-1] == '*'){ // '*' can exhausted multiple char so need recursion to process all the possibilities 
            return dp[i][j] = solve(i-1, j, s, p, dp) || solve(i, j-1, s, p, dp);
        }

        else return dp[i][j] = false;
    } 
    bool isMatch(string s, string p) {
        int n = p.length(), m = s.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        return solve(n, m, s, p, dp);
    }
};

/*
Bottom - Up 

*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length(), m = s.length();
        vector<vector<bool>> dp(n+1, vector<bool> (m+1, 0));
        dp[0][0] = true;

        for(int j=1; j<=m; j++){
            dp[0][j] = false;
        }

        for(int i=1; i<=n; i++){
            bool flag = true;
            for(int k=1; k<=i; k++){
                if(p[k-1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?'){ 
                    dp[i][j] = dp[i-1][j-1];
                }

                else if(p[i-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }

                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};

/*
Space Optimisation 
tc: o(n*m)
sc: o(m)
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length(), m = s.length();

        vector<bool> prev(m+1, false), curr(m+1, false);
        prev[0] = true;

        for(int j=1; j<=m; j++){
            prev[j] = false;
        }

        for(int i=1; i<=n; i++){

            bool flag = true;
            for(int k=1; k<=i; k++){
                if(p[k-1] != '*') {
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;

            for(int j=1; j<=m; j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?'){ 
                    curr[j] = prev[j-1];
                }

                else if(p[i-1] == '*'){
                    curr[j] = prev[j] || curr[j-1];
                }

                else curr[j] = false;
            }
            prev = curr;
        }

        return prev[m];
    }
};





/* ---------------------------------------------My solution---------------------------------------------- */
/*
Top Down Approach 
tc: o(n*m)
sc: o(n*m)
*/ 
class Solution {
public:
    bool solve(int i, int j, string& s, string& p, vector<vector<int>> &dp){
        if(i < 0 && j < 0) return true; // both the string are exhausted, return true

        if(j < 0 && i >= 0) return false; // Only p is exhausted, return false

        if(i < 0 && j >= 0) { // pattern is remaining and it has to '*' to return true
            for(int k=0; k<=j; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(p[j] == s[i] || p[j] == '?'){ // if both the char is same 
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        }

        if(p[j] == '*'){ // '*' can exhausted multiple char so need recursion to process all the possibilities 
            return dp[i][j] = solve(i-1, j, s, p, dp) || solve(i, j-1, s, p, dp);
        }

        return dp[i][j] = false;
    } 
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));

        return solve(n-1, m-1, s, p, dp);
    }
};

/*
Convert into 1 - based solution for bottom - up conversion 
*/
class Solution {
public:
    bool solve(int i, int j, string& s, string& p, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return true; // both the string are exhausted, return true

        if(j == 0 && i > 0) return false; // Only p is exhausted, return false

        if(i == 0 && j > 0) { // pattern is remaining and it has to '*' to return true
            for(int k=1; k<=j; k++){
                if(p[k-1] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(p[j-1] == s[i-1] || p[j-1] == '?'){ // if both the char is same 
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        }

        else if(p[j-1] == '*'){ // '*' can exhausted multiple char so need recursion to process all the possibilities 
            return dp[i][j] = solve(i-1, j, s, p, dp) || solve(i, j-1, s, p, dp);
        }

        else return dp[i][j] = false;
    } 
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        return solve(n, m, s, p, dp);
    }
};

/*
Its always an easy to convert 1-based indexing top down to bottom up approach
By using Bottom - up approach we can eliminate the Stack space. 
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();

        vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));

        // base case
        dp[0][0] = true;
        for(int i=1; i<=n; i++){
            dp[i][0] = false;
        }
        for(int j=1; j<=m; j++){
            int f1 = true;
            for(int k=1; k<=j; k++){
                if(p[k-1] != '*'){
                    f1 = false;
                    break;
                }
            }
            dp[0][j] = f1;
        }

        // choice diagram 
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(p[j-1] == s[i-1] || p[j-1] == '?'){ 
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){ 
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};


// Space optimisation 

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();

        vector<bool> prev(m+1, false), curr(m+1, false);

        // Base case: Empty pattern matches empty string
        prev[0] = true;

        // Base case: Handle pattern starting with '*'
        for(int j = 1; j <= m; j++){
            if (p[j-1] == '*') {
                prev[j] = prev[j-1];  // If pattern is '*', it can match empty string
            } else {
                break;  // Once we find a non-'*', break
            }
        }

        // Choice diagram
        for(int i = 1; i <= n; i++) {
            curr[0] = false;  // No pattern matches a non-empty string
            for(int j = 1; j <= m; j++) {
                if(p[j-1] == s[i-1] || p[j-1] == '?') {
                    curr[j] = prev[j-1];  // Characters match or pattern is '?'
                } 
                else if(p[j-1] == '*') {
                    curr[j] = prev[j] || curr[j-1];  // '*' matches empty or previous character
                } 
                else {
                    curr[j] = false;  // No match
                }
            }
            prev = curr;  // Move to the next state
        }

        return prev[m];  // Result is whether the entire pattern matches the string
    }
};
