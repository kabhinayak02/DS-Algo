/*
using 3-d dp [MLE]

tc: o(n.m.rightSum)
sc: o(n.m.rightSum)
*/
class Solution {
public:
    int solve(int idx, int cnt, int rightSum, vector<vector<int>>& costs, vector<vector<vector<int>>>& dp){
        if(cnt == 0){
            return rightSum;
        }

        if(idx >= costs.size()){
            return 1e9;
        }
        if(dp[idx][cnt][rightSum] != -1) return dp[idx][cnt][rightSum];
        // if(dp[idx][cnt] != -1) return dp[idx][cnt];

        int take = costs[idx][0] + solve(idx+1, cnt-1, rightSum-costs[idx][1], costs, dp);
        int notTake = solve(idx+1, cnt, rightSum, costs, dp);

        return dp[idx][cnt][rightSum] = min(take, notTake);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int m = costs.size();
        int n = m/2;

        int rightSum = 0;
        for(int i=0; i<m; i++){
            rightSum += costs[i][1];
        }
        cout << rightSum << endl;
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(rightSum+1, -1)));
        return solve(0, n, rightSum, costs, dp);
    }
};

/*
using 2-d dp [AC]

tc: o(n.m)
sc: o(n.m)
*/
class Solution {
public:
    int solve(int idx, int cnt, vector<vector<int>>& costs, vector<vector<int>>& dp){
        if(cnt == 0){
            int sum = 0;
            for(int i=idx; i<costs.size(); i++){
                sum += costs[i][1];
            }
            return dp[idx][cnt] = sum;
        }

        if(idx >= costs.size()) return 1e9;

        if(dp[idx][cnt] != -1) return dp[idx][cnt];

        int take = costs[idx][0] + solve(idx+1, cnt-1, costs, dp);
        int notTake = costs[idx][1] + solve(idx+1, cnt, costs, dp);

        return dp[idx][cnt] = min(take, notTake);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int m = costs.size();
        int n = m/2;
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return solve(0, n, costs, dp);
    }
};


/*
using greedy (most optimal)

tc: o(nlogn)
sc: o(1)
*/
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // Sort by the difference in costs between city A and city B
        sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });

        int totalCost = 0;
        int n = costs.size() / 2;

        // Sum up the cost for the first n people to go to city A 
        // and the remaining n people to go to city B
        for (int i = 0; i < n; i++) {
            totalCost += costs[i][0];      // City A cost for first n people
            totalCost += costs[i + n][1];  // City B cost for remaining n people
        }

        return totalCost;
    }
};