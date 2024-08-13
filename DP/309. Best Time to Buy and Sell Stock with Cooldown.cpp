#include <vector>
#include <unordered_map>
using namespace std;

// Recursion + Memoisation 
// tc: o(n^2)
// sc: o(n)
class Solution {
public:
    int t[5001][2];
    int solve(int day, bool buy, int n, vector<int>& prices){
        if(day >= n) return 0;

        if(t[day][buy] != -1) return t[day][buy];

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

        return t[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(t, -1, sizeof(t));
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

        //t[i] = max profit at the end of ith day
        vector<int> t(n, 0);
        t[0] = 0; //no profit on 0th day
        t[1] = max(prices[1]-prices[0], 0);

        for(int i=2; i<n; i++){
            t[i] = t[i-1];
            for(int j=0; j<=i-1; j++){  //find best buy day from j  = 0 to i-1
                int todayProfit = prices[i] - prices[j];
                int prevProfit = (j >= 2)? t[j-2] : 0;
                t[i] = max(t[i], todayProfit+prevProfit);
            }
        }
        return t[n-1];
    }
};