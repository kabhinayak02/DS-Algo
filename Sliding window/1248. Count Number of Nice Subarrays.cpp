/*
using variable size sliding window 

tc: o(n)
sc: o(1)
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int cntOdd = 0, ans = 0;
        int countLeft = 0; // Tracks subarrays starting from valid positions
        
        while (j < n) {
            if (nums[j] % 2 != 0) {
                cntOdd++;
                countLeft = 0; // Reset count of valid subarrays
            }
            
            while (cntOdd == k) {
                if (nums[i] % 2 != 0) cntOdd--;
                countLeft++;
                i++;
            }
            
            ans += countLeft; // Add valid subarrays ending at j
            j++;
        }
        
        return ans;
    }
};