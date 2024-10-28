/*

tc: o(nlogn)
sc: o(n)
*/

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int,int> mp;
        int ans = -1;
        for(auto &num: nums){
            int sr = sqrt(num);
            if(sr*sr == num && mp.find(sr) != mp.end()){
                mp[num] = mp[sr] + 1;
                ans = max(ans, mp[num]);
            }
            else{
                mp[num] = 1; 
            }
        }
        return ans;

    }
};