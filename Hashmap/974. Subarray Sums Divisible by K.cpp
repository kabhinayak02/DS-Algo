/*
brute force [TLE]

tc: o(n^3)
sc: o(1)
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int sum = 0;    
                for(int k=i; k<=j; k++){
                    sum += nums[k];
                }
                if(sum % k == 0) cnt++;
            }
        }
        return cnt;
    }
};

/*
[TLE]
tc: o(n^2) 
sc: o(1)
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(sum % k == 0) cnt++;
            }
        }
        return cnt;
    }
};

/*
[TLE]
tc: o(n^2)
sc: o(1)

*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=1; i<n; i++){
            nums[i] += nums[i-1];
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int sum = (i == 0) ? nums[j] : nums[j] - nums[i-1];
                if(sum % k == 0) cnt++;
            }
        }
        return cnt;
    }
};

/*
using unordered map
Optimised [Accepted]

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int sum = 0;
        mp[0] = 1;
        int ans = 0; 
        for(int i=0; i<n; i++){
            sum += nums[i];
            int rem = sum%k;

            if(rem < 0) rem += k;

            if(mp.find(rem) != mp.end()){
                ans += mp[rem];
            }
            mp[rem]++;
        }
        return ans;
    }
};