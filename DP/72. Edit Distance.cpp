

class Solution {
public:
    int t[501][501];
    int solve(int i, int j, string &word1, string &word2){
        if(i >= word1.size()) return word2.size() - j;
        if(j >= word2.size()) return word1.size() - i;

        if(t[i][j] != -1) return t[i][j];

        if(word1[i] == word2[j]){
            return t[i][j] = solve(i+1, j+1, word1, word2);
        }

        int deleteWord= solve(i+1, j, word1, word2);
        int replaceWord = solve(i+1, j+1, word1, word2);
        int insertWord = solve(i, j+1, word1, word2);

        return t[i][j] = 1 + min({deleteWord, replaceWord, insertWord});
    }
    int minDistance(string word1, string word2) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, word1, word2);
    }
};


// same code but with traverse from left to right. 
class Solution {
public:
    int t[501][501];
    int solve(int n, int m, string &word1, string &word2){
        if(n == 0 || m == 0){
            return m + n;
        } 

        if(t[n][m] != -1) return t[n][m];

        if(word1[n-1] == word2[m-1]){
            return t[n][m] = solve(n-1, m-1, word1, word2);
        }

        int deleteWord = 1 + solve(n-1, m, word1, word2);
        int replaceWord = 1 + solve(n-1, m-1, word1, word2);
        int insertWord = 1 + solve(n, m-1, word1, word2);

        return t[n][m] = min({deleteWord, replaceWord, insertWord});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        memset(t, -1, sizeof(t));
        return solve(n, m, word1, word2);
    }
};


// bottom up: (It easy to convert the code from above approach to bottom up code)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        int t[n+1][m+1];
        memset(t, 0, sizeof(t));

        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i == 0 || j == 0){
                    t[i][j] = i + j;
                }
                else if(word1[i-1] == word2[j-1]){
                    t[i][j] = t[i-1][j-1];
                }
                else{
                    t[i][j] = min({1 + t[i-1][j], 1 + t[i-1][j-1], 1 + t[i][j-1]});
                }
            }
        }
        return t[n][m];
    }
}; 