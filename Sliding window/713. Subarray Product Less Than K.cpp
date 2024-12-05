/*
Brute force: Find all the subarray and check for the product of each subarray with strictly less than k

tc: o(n.n.n) 
sc: o(1)
*/



/*
variable size sliding window


tc: o(n)
sc: o(1)
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0) return 0;
        int n = nums.size();
        int i = 0, j = 0;
        int ans = 0;
        int pro = 1;

        while(j < n){
            pro *= nums[j];
            while(pro >= k){
                pro /= nums[i];
                i++;
            }
            ans += (j-i+1); // no. of subarray ending at j; [imp]
            j++;
        }
        return ans;
    }
};