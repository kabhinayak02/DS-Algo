/*
using sliding window

variable size window: traverse j'th index on nums array and add the element in variable sum
and check if sum >= target if it it, loop till it become equal to target and check for the 
required ans

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int sum = 0;
        int ans = INT_MAX;
        while (j < nums.size()) {
            sum += nums[j]; // Include the current element in the window
            while (sum >= target) {
                ans = min(ans, j - i + 1); // Update the minimum window size
                sum -= nums[i]; // Shrink the window from the left
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
