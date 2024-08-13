#include <vector>
#include <unordered_map>
using namespace std;

// Recursion + Memoisation 
// tc: o(n^2)
// sc: o(n^2)
class Solution {
public:
    static bool myFunction(string &word1, string &word2){
        return word1.length() < word2.length();
    }

    bool check(string &prev, string &curr){ 
        int n = prev.length(), m = curr.length();
        if(m-n != 1 || n >= m) return false;

        int i=0, j=0;
        while(i < n && j < m){
            if(prev[i] == curr[j]){
                i++;
            }
            j++;
        }

        return i == n;
    }
    
    int t[1001][1001];
    int solve(int i, int prev, int n, vector<string> &words){
        if(i >= n) return 0;

        if(t[i][prev+1] != -1) return t[i][prev+1];

        int choose = 0, notChoose = 0;
        if(prev == -1 || check(words[prev], words[i]) == true){
            choose = 1 + solve(i+1, i, n, words);
        }
        notChoose = solve(i+1, prev, n, words);

        return t[i][prev+1] = max(choose, notChoose);
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        memset(t, -1, sizeof(t));
        sort(words.begin(), words.end(), myFunction);

        return solve(0, -1, n, words);
    }
};


// Bottom Up 
// tc: o(n^2)
// sc: o(n)
class Solution {
public:
    static bool myFunction(string &word1, string &word2){
        return word1.length() < word2.length();
    }

    bool check(string &prev, string &curr){ 
        int n = prev.length(), m = curr.length();
        if(m-n != 1 || n >= m) return false;

        int i=0, j=0;
        while(i < n && j < m){
            if(prev[i] == curr[j]){
                i++;
            }
            j++;
        }

        return i == n;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), myFunction);

        vector<int> dp(n, 1);

        int maxLen = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                string prev = words[j];
                string curr = words[i];
                if(check(prev, curr)){
                    dp[i] = max(dp[i], dp[j]+1);
                    maxLen = max(maxLen, dp[i]);
                }
            }
        }
        return maxLen;
    }
};