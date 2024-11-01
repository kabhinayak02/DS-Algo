/*
using LIS 

tc: o(n.n)
sc: o(n)
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, vector<int>& dp) {
        int n = nums.size();

        int maxLen = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                    maxLen = max(maxLen, dp[i]);
                }
            }
        }
        return maxLen;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1), lds(n, 1);

        lengthOfLIS(nums, lis);
        reverse(nums.begin(), nums.end());
        
        lengthOfLIS(nums, lds);
        reverse(lds.begin(), lds.end());

        int ans = n;
        for(int i=0; i<n; i++){
            if(lis[i] > 1 && lds[i] > 1){
                ans = min(ans, n-lis[i]-lds[i]+1);
            }
        }
        return ans;
    }
};


/*
better way to code 

tc: o(n.n)
sc: o(n)
*/
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1), lds(n, 1);

        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i] > nums[j]){
                    lis[i] = max(lis[i], lis[j]+1);
                }
            }
        }

        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(nums[i] > nums[j]){
                    lds[i] = max(lds[i], lds[j]+1);
                }
            }
        }

        int ans = n;
        for(int i=0; i<n; i++){
            if(lis[i] > 1 && lds[i] > 1){
                ans = min(ans, n-lis[i]-lds[i]+1);
            }
        }
        return ans;
    }
};