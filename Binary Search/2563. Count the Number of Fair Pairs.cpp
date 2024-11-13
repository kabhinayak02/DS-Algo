/*
brute force approach [TLE]

tc: o(n.n)
sc: o(1)
*/
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size(), cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int sum = nums[i] + nums[j];
                if(sum >= lower && sum <= upper) cnt++;
            }
        }
        return cnt;
    }
};


/*
using binary search (upper bound and lower bound)

tc: o(nlogn)
sc: o(1)
*/
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            int idx = lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i]) - nums.begin(); // gives index 
            int x = idx - 1 - i; 

            idx = upper_bound(nums.begin()+i+1, nums.end(), upper-nums[i]) - nums.begin(); // gives index 
            int y = idx - 1 - i;

            ans += (y-x);
        }
        return ans;
    }
};