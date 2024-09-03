/*
Brute force 

tc: o(n) ,     o(nlogn) in the case of using map instead of unordered_map
sc: o(n)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;

        for(int num: nums){
            freq[num]++;
        }

        for(auto& i: freq){
            if(i.second == 1) return i.first;
        }
        return -1;
    }
};


/*
Xor of same number is 0, So remaining number will be the single number

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0];
        for(int i=1; i<nums.size(); i++){
            a = a ^ nums[i];
        }
        return a;
    }
};