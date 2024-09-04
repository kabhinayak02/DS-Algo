/*
[Brute force] Using Map

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(auto& num: nums){
            freq[num]++;
        }
        
        vector<int> ans;
        for(auto& i: freq){
            if(i.second == 1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};

/*
Using Bit Manipulation

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long xxor = 0;
        for(int i=0; i<n; i++){
            xxor = xxor ^ nums[i]; // xor of two distinct no.
        }
        long rightmost = (xxor & (xxor-1)) ^ xxor; // gives the right most set bit 
        int b1 = 0, b2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] & rightmost){ // if right most bit is 1 (set)
                b1 = b1 ^ nums[i]; 
            }
            else{                    // if right most bit is 0 (not set)
                b2 = b2 ^ nums[i];
            }
        }
        return {b1, b2};
    }
};