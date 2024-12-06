/*
fixed size sliding window 

tc: o(n)
sc: o(k)
*/
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        unordered_map<int,int> mp;
        long long sum = 0, ans = 0;
        while(j < n){
            sum += nums[j];
            mp[nums[j]]++;

            if(j-i+1 > k){
                sum -= nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            
            if(j-i+1 == k && mp.size() == k){
                ans = max(ans, sum);  
            }
            
            j++;
        }
        return ans;
    }
};