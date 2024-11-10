/*
using sliding window and bitmasking 

tc: 
sc:
*/
class Solution {
public:
    void update(int num, vector<int>& bitCount, int val){
        for(int i=0; i<32; i++){
            if(num & (1 << i)){
                bitCount[i]+=val;
            }
        }
    }
    int getDecimalFromBinary(vector<int> &bitCount){
        int num = 0;
        for(int i=0; i<32; i++){
            if(bitCount[i] > 0){
                num |= (1 << i);
            }
        }
        return num;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        int i = 0, j = 0;
        vector<int> bitCount(32, 0);

        while(j < n){
            update(nums[j], bitCount, 1);
            while(i <= j && getDecimalFromBinary(bitCount) >= k){
                ans = min(ans, j-i+1);
                update(nums[i], bitCount, -1);
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};