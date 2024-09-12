/*
Solve using Backtracking

Can also solve using Bit Manipulation, see Bit Manipulation solution 

Time Complexity: O(2^n)
Space Complexity: O(2^n)
*/
class Solution {
public:
    void solve(int ind, vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums){
        if(ind >= nums.size()){ // base case 
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]); // take 
        solve(ind+1, temp, ans, nums); // explore 
        temp.pop_back(); // not take
        solve(ind+1, temp, ans, nums); // and explore 
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;

        solve(0, temp, ans, nums);
        return ans;
    }
};


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