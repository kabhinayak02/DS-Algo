/*
[TLE] Brute force 

tc: o(n^2)
sc: o(1)
*/
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int ramp = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] <= nums[j]){
                    ramp = max(ramp, j-i);
                }
            }     
        }
        return ramp;
    }
};

/*
using 2 pointer

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxRight(n);
        maxRight[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            maxRight[i] = max(maxRight[i+1], nums[i]);
        }
        int ans = 0;
        int i = 0, j = 1;
        while(j < n){
            if(nums[i] <= maxRight[j]){
                ans = max(ans, j - i);
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};

/*
Same solution as above 
*/
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
 
        vector<int> rightMax(n);
        rightMax[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], nums[i]);
        }

        int ramp = 0;
        int i = 0, j = 0;
        while(j < n){
            while(i < j && nums[i] > rightMax[j]){
                i++;
            }
            ramp = max(ramp, j-i);
            j++;
        }
        
        return ramp;
    }
};