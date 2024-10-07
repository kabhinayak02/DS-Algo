/*

use a unordered map to stores the curr%p (cummulative sum) with their indexes.
tc: o(n)
sc: o(1)
*/
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int sum = 0;
        for(int num: nums){
            sum = (sum + num)%p;
        }
        int target = sum % p;

        if(target == 0) return 0;

        unordered_map<int,int> mp;

        int curr = 0; // cummulative sum 
        mp[0] = -1; // {curr = 0, -1}

        int ans = n;
        for(int i=0; i<n; i++){
            curr = (curr + nums[i]) % p;

            int remain = (curr - target + p) % p; // to handle -ve case also

            if(mp.find(remain) != mp.end()){
                ans = min(ans, i - mp[remain]);
            }

            mp[curr] = i;
        }
        return ans == n ? -1 : ans;

    }
};