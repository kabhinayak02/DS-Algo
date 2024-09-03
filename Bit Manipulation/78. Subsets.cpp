/*
Solve using Bit Manipulation

Can also solve using backtracting, see backtracking solution 

Time Complexity: O(n*2^n)
Space Complexity: O(n*2^n) [near about]]
*/

class Solution {
public:
    typedef long long ll;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        ll totalSubsets = 1 << n;

        for(ll i=0; i<totalSubsets; i++){
            vector<int> arr;

            for(int j=0; j<n; j++){
                if(i & (1 << j)){
                    arr.push_back(nums[j]);
                }
            }
            ans.push_back(arr);
        }
        return ans;
    }
};