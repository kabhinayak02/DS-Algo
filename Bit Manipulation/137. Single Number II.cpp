/*
[Brute force] Using Map

tc: o(n)
sc: o(n)

*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num: nums){
            freq[num]++;
        }
        for(auto& i: freq){
            if(i.second != 3) return i.first;
        }
        return -1;
    }
};

/*
Using Bit manipulation

tc: o(n.32)
sc: o(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int bitset = 0; bitset <= 31; bitset++){
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(nums[i] & (1 << bitset)){
                    cnt++;
                }   
            }
            if(cnt%3 == 1){
                ans = ans | (1 << bitset);
            }
        }
        return ans;
    }
};

/*
using sorting

tc: (nlogn)
sc: o(1)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=1; i<n; i+=3){
            if(nums[i-1] != nums[i]){
                return nums[i-1];
            }
        }
        return nums[n-1];
    }
};

/*
Bit maniplution [Not inituitive]

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ones = 0, twos = 0;
        for(int i=0; i<n; i++){
            ones = (ones ^ nums[i]) & ~(twos);
            twos = (twos ^ nums[i]) & ~(ones);
        }
        return ones;
    }
};