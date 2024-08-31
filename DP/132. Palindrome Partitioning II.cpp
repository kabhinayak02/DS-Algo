/*
[TLE Solution] DP Approach: Recursion + Memoisation

tc: o(n^3)
sc: o(n^2)
*/
class Solution {
public:
    bool isPalindrome(string& s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    int t[2001][2001];
    int solve(string& s, int i, int j){
        if(i >= j){
            return 0;
        }
        if(t[i][j] != -1) return t[i][j];

        if(isPalindrome(s, i, j)){
            return 0;
        }
        int cuts = INT_MAX;
        for(int k=i; k<=j-1; k++){
            int temp = 1 + solve(s, i, k) + solve(s, k+1, j);
            cuts = min(cuts, temp);
        }

        return t[i][j] = cuts;
    }
    int minCut(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        return solve(s, 0, n-1);
    }
};

/*
[Accepted] Bottom Up Approach

tc: o(n^2)
sc: o(n^2)
*/

class Solution {
public:
    int minCut(string s) {
        int n = s.length();

        // t[i][j] = true/false, s[i..j] is palindrome or not
        vector<vector<bool>> t(n, vector<bool> (n, false));

        // for len = 1
        for(int i = 0; i < n; i++) {
            t[i][i] = true; // s[i..i] is always a palindrome
        }

        // for len >= 2
        for(int L = 2; L <= n; L++) {
            for(int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1; // Corrected index calculation

                if(L == 2) { // string of size 2 only
                    t[i][j] = (s[i] == s[j]);
                } else {
                    t[i][j] = (s[i] == s[j] && t[i + 1][j - 1]); // Corrected check for larger palindromes
                }
            }
        }

        // dp[i] gives the min cuts needed to make string s[0..i] palindrome
        vector<int> dp(n, INT_MAX);

        for(int i = 0; i < n; i++) {
            if(t[0][i]) { // if s[0..i] is a palindrome
                dp[i] = 0; // no cuts required
            } else {
                for(int k = 0; k < i; k++) {
                    if(t[k + 1][i] && 1 + dp[k] < dp[i]) { // check if the cuts are valid
                        dp[i] = 1 + dp[k];
                    }
                }
            }
        }

        return dp[n - 1]; // min cuts needed to make the entire string a palindrome
    }
};
