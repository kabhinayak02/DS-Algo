/*
using top down approach 

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    int mod = 1e9+7;
    int solve(int len, int low, int high, int zero, int one, vector<int>& dp){
        if(len > high) return 0;
        if(dp[len] != -1){
            return dp[len];
        }
        int chooseOne = solve(len+one, low, high, zero, one, dp);
        int chooseZero = solve(len+zero, low, high, zero, one, dp);

        if(len <= high && len >= low){
            return dp[len] = (1 + chooseOne + chooseZero)%mod;
        }
        return dp[len] = (chooseOne + chooseZero)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, -1);
        int ans = solve(0, low, high, zero, one, dp);
        return ans;
    }
};

/*
using bottom up approach 

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    int mod = 1e9+7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> t(high+1, 0);
        t[0] = 1;
        for(int i=1; i<=high; i++){
            if((i-one) >= 0){
                t[i] = ((t[i])%mod + (t[i-one])%mod)%mod;
            }

            if((i-zero) >= 0){
                t[i] = ((t[i])%mod + (t[i-zero])%mod)%mod;
            }
        }
        int ans = 0;
        for(int i=low; i<=high; i++){
            ans = (ans + t[i])%mod;
        }
        return ans;
    }
};