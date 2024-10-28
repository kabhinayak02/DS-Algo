/*
using unordered_map

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

/*
using unordered_set

tc: o(n * 5) = o(n)
sc: o(n)
*/
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for(int num: nums){
            int streak = 0;
            long long curr = num;

            while(st.find(curr) != st.end()){
                streak++;
                if(curr*curr > 1e5){
                    break;
                } 
                curr = curr*curr;
            }
            ans = max(ans, streak);
        }
        return ans < 2 ? -1: ans;
    }
};