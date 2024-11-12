/*
using dp with num value instead of index i 

tc: o(n)
sc: o(100001)
*/

class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        int MAX = 100001;
        int mod = 1e9+7;
        
        vector<long> sum(MAX, 0);
        vector<long> dp(MAX, 0);

        for(int &num: nums){
            dp[num] = (dp[num]+1)%mod;
            sum[num] = (sum[num]+num)%mod;

            if(num-1 >= 0 && dp[num-1] > 0){
                dp[num] = (dp[num] + dp[num-1])%mod;
                sum[num] = (sum[num] + sum[num-1] + (dp[num-1]*num)%mod)%mod;
            }

            if(num+1 < MAX && dp[num+1] > 0){
                dp[num] = (dp[num] + dp[num+1])%mod;
                sum[num] = (sum[num] + sum[num+1] + (dp[num+1]*num)%mod)%mod;
            }
        }
        long ans = 0;
        for(int i=0; i<MAX; i++){
            ans = (ans + sum[i])%mod;
        }
        return (int)ans;
    }
};