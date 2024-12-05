/*
variable size sliding window 

tc: o(n)
sc: o(1)
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;

        int zero = 0;
        int ans = 0;

        while(j < n){
            if(nums[j] == 0) zero++;
            while(zero > k){
                if(nums[i] == 0) zero--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};