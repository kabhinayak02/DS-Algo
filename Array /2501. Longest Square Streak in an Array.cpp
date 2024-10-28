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


/*
using binary search 

tc: o(nlogn)
sc: o(n)
*/
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> dp(n, 1);
        for(int i=0; i<n; i++){
            long long search = (long long)nums[i]*nums[i];
            int start = i+1, end = n-1;
            while(start <= end){
                int mid = start + (end - start) / 2;
                if(search == nums[mid]){
                    dp[mid] = max(dp[mid], dp[i] + 1);
                    break;
                }
                else if(search < nums[mid]){
                    end = mid-1;
                }
                else {
                    start = mid+1;
                }
            }
        }
        int ans = *max_element(dp.begin(), dp.end());
        return ans < 2 ? -1 : ans;
    }
};