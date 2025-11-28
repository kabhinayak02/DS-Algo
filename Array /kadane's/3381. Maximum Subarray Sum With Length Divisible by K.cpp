class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum;

        long long sum = 0;
        for(int num: nums){
            sum += num;
            prefixSum.push_back(sum);
        }

        long long ans = LLONG_MIN;

        for(int start=0; start<k; start++){
            long long currSum = 0;
            int i = start;

            while(i < n && i+k-1 < n){
                int j = i+k-1;

                long long subSum = prefixSum[j] - ((i > 0) ? prefixSum[i-1] : 0);

                currSum = max(subSum, currSum+subSum);
                ans = max(ans, currSum);

                i += k;

            }
        }
        return ans;
    }
};