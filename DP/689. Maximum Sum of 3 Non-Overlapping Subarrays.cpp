/*
using dp memoisation 


1: pre-compute the subarray sum using sliding window, it help us to find the subarray sum in o(1)
2: use recusrion to take & not take i of the given array 
3: make another recursive helper function to find the possible sum and memoise it.


tc: o(n) + o(n) 
sc: o(n)
*/
class Solution {
public:
    int t[20001][4];
    int helper(int count, int i, int k, vector<int>& subarray){
        if(count == 0){
            return 0;
        }
        if(i >= subarray.size()){
            return INT_MIN;
        }

        if(t[i][count] != -1){
            return t[i][count];
        }

        int take_i = subarray[i] + helper(count-1, i+k, k, subarray);
        int not_take_i = helper(count, i+1, k, subarray);

        return t[i][count] = max(take_i, not_take_i);
    }
    void solve(int i, int count, int k, vector<int>& subarray, vector<int>& ans){
        if(count == 0){
            return;
        }
        if(i >= subarray.size()){
            return;
        }

        int take_i = subarray[i] + helper(count-1, i+k, k, subarray);
        int not_take_i = helper(count, i+1, k, subarray);

        if(take_i >= not_take_i){
            ans.push_back(i);
            solve(i+k, count-1, k, subarray, ans);
        }
        else{
            solve(i+1, count, k, subarray, ans);
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        memset(t, -1, sizeof(t));
        int i = 0, j = 0;
        int sum = 0;
        vector<int> subarray;
        while(j < nums.size()){
            sum += nums[j];
            if(j-i+1 == k){
                subarray.push_back(sum);
                sum -= nums[i];
                i++;
            }
            j++;
        }

        vector<int> ans;
        solve(0, 3, k, subarray, ans);
        return ans;
    }
};