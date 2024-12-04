/*
similar leetcode problem: https://leetcode.com/problems/sort-colors/description/

*/

/*
Brute force

tc: o(nlogn);
sc: o(1)
*/
class Solution {
  public:
    void sort012(vector<int>& arr) {
       sort(arr.begin(), arr.end());
    }
};

/*
using map or vector of size 3

tc: o(n), 2 passes 
sc: o(3), 3 variables 
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;

        for(auto &num: nums){
            if(num == 0) zero++;
            else if(num == 1) one++;
            else two++;
        }
        int i = 0;
        while(zero--){
            nums[i] = 0;
            i++;
        }
        while(one--){
            nums[i] = 1;
            i++;
        }
        while(two--){
            nums[i] = 2;
            i++;
        }
    }
};


/*
Dutch National Flag Algorithm: optimised Approach 

mid positions are for 1 so pointer j will take care of it so when we traverse the j pointer we will get 0, 1 and 2 
when we get 0 swap it with i, if 1 skip just move forward and if 2 swap it with k. As k will start from back 
because after sorting we know that 2 will always in the last. i, and j will start from front 

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, k = n-1;
        // i -> 0
        // j -> 1
        // k -> 2
        while(j <= k){
            if(nums[j] == 0){ // swip it to i'th index as pointer i will take care of '0'
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else if(nums[j] == 1){ //correct position, dont neet to change just move forward 
                j++;
            }
            else{ // if j == 2, swap it with k, as pointer k will take care of it
                swap(nums[j], nums[k]);
                k--;
            }
        }
    }
};

