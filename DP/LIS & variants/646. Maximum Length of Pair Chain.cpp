#include <vector>
#include <unordered_map>
using namespace std;


// Recursion + Memoisation
// tc: o(n^2)
// sc: o(n^2)
class Solution {
public:
    int t[1001][1001];
    int solve(int i, int prev, int n, vector<vector<int>>& pairs){
        if(i >= n) return 0;

        if(t[i][prev+1] != -1) return t[i][prev+1];

        int choose = 0, notChoose = 0;
        if(prev == -1 || pairs[prev][1] < pairs[i][0]){
            choose = 1 + solve(i+1, i, n, pairs);
        }
        notChoose = solve(i+1, prev, n, pairs);

        return t[i][prev+1] = max(choose, notChoose);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        memset(t, -1, sizeof(t));
        sort(pairs.begin(), pairs.end());

        return solve(0, -1, n, pairs);
    }
};


// Bottom Up
// tc: o(n^2)
// sc: o(n)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());

        vector<int> dp(n, 1);

        int maxLen = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[i], dp[j]+1);
                    maxLen = max(maxLen, dp[i]);
                }
            }
        }
        return maxLen;
    }
};