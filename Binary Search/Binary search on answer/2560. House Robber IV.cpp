/*
using DP [TLE]

tc: o(n.n)
sc: o(n.n)
*/
class Solution {
public:
    int n;
    int solve(int i, vector<int>& nums, int k, vector<vector<int>>& dp){
        if(k == 0){
            return 0;
        }

        if(i >= n){ // invalid path 
            return INT_MAX;
        }

        if(dp[i][k] != -1){
            return dp[i][k];
        }

        int take = max(nums[i], solve(i+2, nums, k-1, dp));
        int not_take = solve(i+1, nums, k, dp);

        return dp[i][k] = min(take, not_take);
    }
    int minCapability(vector<int>& nums, int k) {
        n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
        return solve(0, nums, k, dp);
    }
};

/*
Using binary search on ans [AC]

tc: o(nlogn)
sc: o(1)
*/
class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int mid){
        int house = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= mid){
                house++;
                i++;
            }
        }
        return house >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        int ans = r;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(isPossible(nums, k, mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};