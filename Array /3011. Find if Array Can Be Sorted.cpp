/*
using bubble sort logic 

tc: o(n.n)
sc: o(1)
*/
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        bool swapped = false;
        for(int i=0; i<n; i++){
            swapped = false;
            for(int j=0; j<n-i-1; j++){
                if(nums[j] <= nums[j+1]){ // alread sorted, no swap required 
                    continue;
                }
                else {
                    if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1])){ // swap only when bit count is equal 
                        swap(nums[j], nums[j+1]);
                        swapped = true;
                    }
                    else{ // if we can't able to do it means we can't sort the array 
                        return false;
                    }
                }
            }
            if(swapped == false){ // no swap was done in last loop, so comming all loops will no effect 
                break;
            }
        }
        return true;
    }
};

/*

make a group of same bit count array or think it like a subarray of same bit counts, now compare the max Element from 
the previuos subarray to min Element from the current subarray, if CurrMinEle > prevMaxElement then element from 
their subarray remains in their own subarray, no element exchange will happen. 


tc: o(n)
sc: o(1)
*/

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int check = __builtin_popcount(nums[0]);
        int maxEle = INT_MIN, prevMaxEle = INT_MIN;
        int minEle = INT_MAX;
        
        for(int i = 0; i < n;) {
            // Find max and min elements in current group with same bit count
            while(i < n && check == __builtin_popcount(nums[i])) {
                maxEle = max(maxEle, nums[i]);
                minEle = min(minEle, nums[i]);
                i++;
            }
            
            // Check if current group's minimum is less than previous group's maximum
            if(prevMaxEle != INT_MIN && minEle < prevMaxEle) 
                return false;
            
            // Update for next group
            prevMaxEle = maxEle;
            if(i < n) {
                check = __builtin_popcount(nums[i]);
                maxEle = INT_MIN;
                minEle = INT_MAX;
            }
        }
        return true;
    }
};