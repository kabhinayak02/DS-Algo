/*
Solve using Backtracking

Can also solve using Bit Manipulation, see Bit Manipulation solution 

Time Complexity: O(2^n)
Space Complexity: O(2^n)
*/

class Solution {
private:
    void solve(vector<int>& nums, vector<int> &temp, vector<vector<int>>& ans, int ind){
        ans.push_back(temp);
        for(int i=ind; i<nums.size(); i++){
            temp.push_back(nums[i]);
            solve(nums, temp, ans, i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums, temp, ans, 0);
        return ans;
    }
};