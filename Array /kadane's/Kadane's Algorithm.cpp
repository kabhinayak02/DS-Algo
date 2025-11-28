/*
Gfg Problem: Kadane's Algorithm
Link: https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1


Give solution can handle negative element in the array 
*/

class Solution {
  public:
    long long maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        
        int ma = *max_element(arr.begin(), arr.end());
        if(ma < 0){
            return ma;
        }

        int totalSum = INT_MIN, currSum = 0;
        for(int i=0; i<n; i++){
            currSum += arr[i];
            if(currSum > totalSum){
                totalSum = currSum;
            }
            if(currSum < 0){
                currSum = 0;
            }
        }
        return totalSum;
    }
};