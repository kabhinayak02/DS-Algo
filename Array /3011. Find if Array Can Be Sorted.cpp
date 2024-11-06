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