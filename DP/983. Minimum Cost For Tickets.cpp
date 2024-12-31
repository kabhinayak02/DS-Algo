/*
using 2D dp

tc: o(n.365)
sc: o(n.365)
*/
class Solution {
public:
    int solve(int i, int day, vector<int>& days, vector<int>& costs, vector<vector<int>>& dp){ // return total mini costs
        if(i >= days.size()){
            return 0;
        }
        if(day >= days[i]) {
            return solve(i+1, day, days, costs, dp);
        }

        if(dp[i][day] != -1){
            return dp[i][day];
        }

        int choose_1 = costs[0] + solve(i+1, days[i]+1-1, days, costs, dp);
        int choose_7 = costs[1] + solve(i+1, days[i]+7-1, days, costs, dp);
        int choose_30 = costs[2] + solve(i+1, days[i]+30-1, days, costs, dp);

        return dp[i][day] = min({choose_1, choose_7, choose_30});

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> dp(days.size(), vector<int>(365, -1));
        return solve(0, 0, days, costs, dp);
    }
};

/*
using 1-D dp 

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    int nextValidIndex(int currIdx, int day, vector<int>& days){
        int n = days.size();
        while(currIdx < n && days[currIdx] <= day){
            currIdx++;
        }
        return currIdx;
    }
    int solve(int i, vector<int>& days, vector<int>& costs, vector<int>& dp){
        if(i >= days.size()){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int choose_1 = costs[0] + solve(nextValidIndex(i, days[i], days), days, costs, dp);
        int choose_7 = costs[1] + solve(nextValidIndex(i, days[i]+6, days), days, costs, dp);
        int choose_30 = costs[2] + solve(nextValidIndex(i, days[i]+29, days), days, costs, dp);

        return dp[i] = min({choose_1, choose_7, choose_30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return solve(0, days, costs, dp);
    }
};