// Recursion + Memoisation 
// tc: o(n^2)
// sc: o(n)
class Solution {
public:
    int dp[5001][2];
    int solve(int day, bool buy, int n, vector<int>& prices){
        if(day >= n) return 0;

        if(dp[day][buy] != -1) return dp[day][buy];

        int profit = 0;
        if(buy){
            int take = solve(day+1, false, n, prices) - prices[day];
            int notTake = solve(day+1, true, n, prices);
            profit = max({profit, take, notTake});
        }
        else{
            int sell = solve(day+2, true, n, prices) + prices[day];
            int notSell = solve(day+1, false, n, prices);
            profit = max({profit, sell, notSell});
        }

        return dp[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, true, n, prices);
    }
};

// Bottom Up 
// tc: o(n^2)
// sc: o(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || n == 1) return 0;

        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = max(prices[1]-prices[0], 0);

        for(int i=2; i<n; i++){
            dp[i] = dp[i-1];
            for(int j=0; j<=i-1; j++){
                int todayProfit = prices[i] - prices[j];
                int prevProfit = (j >= 2)? dp[j-2] : 0;
                dp[i] = max(dp[i], todayProfit+prevProfit);
            }
        }
        return dp[n-1];
    }
};