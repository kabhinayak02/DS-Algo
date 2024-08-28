
/*
Using Kadane's Algorithm

The idea behind Kadane's Algorithm is to iterate through the array while keeping a running sum `sum` of 
the current subarray. If the running sum becomes negative, it is reset, as a negative sum would not 
contribute positively to the subsequent subarrays. The variable `maxSum` keeps track of the maximum sum 
encountered during the iteration.

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxSum = INT_MIN;

        for(int i=0; i<n; i++){
            sum = sum + nums[i];
            maxSum = max(maxSum, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return maxSum;
    }
};

