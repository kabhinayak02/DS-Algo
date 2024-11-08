/*
using XOR property (Bit manipulation)

tc: o(n)
sc: o(n)
*/

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans(n);
        int XOR = 0;
        for(int i=0; i<n; i++){
            XOR ^= nums[i];
        }
        
        // need the mask to find the flip of the XOR i.e k
        int mask = ((1 << maximumBit) - 1);

        for(int i=0; i<n; i++){
            int k = XOR ^ mask;
            ans[i] = k;

            XOR = (XOR ^ nums[n-i-1]);
        }
        return ans;
    }
};