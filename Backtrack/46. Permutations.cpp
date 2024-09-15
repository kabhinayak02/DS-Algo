/*
Using swap 

Explaination:
solve(0, [1, 2, 3])
   |
   |-- solve(1, [1, 2, 3])
   |     |
   |     |-- solve(2, [1, 2, 3]) → [1, 2, 3] (add to ans)
   |     |-- solve(2, [1, 3, 2]) → [1, 3, 2] (add to ans)
   |
   |-- solve(1, [2, 1, 3])
   |     |
   |     |-- solve(2, [2, 1, 3]) → [2, 1, 3] (add to ans)
   |     |-- solve(2, [2, 3, 1]) → [2, 3, 1] (add to ans)
   |
   |-- solve(1, [3, 2, 1])
         |
         |-- solve(2, [3, 2, 1]) → [3, 2, 1] (add to ans)
         |-- solve(2, [3, 1, 2]) → [3, 1, 2] (add to ans)
         
*/
class Solution {
public:
    void solve(int begin, vector<int>& nums, vector<vector<int>>& ans){
        if(begin >= nums.size()){
            ans.push_back(nums);
        }
        for(int i=begin; i<nums.size(); i++){
            swap(nums[begin], nums[i]);
            solve(begin+1, nums, ans);
            swap(nums[begin], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
};

/*


*/
class Solution {
private: 
    int n;
    vector<vector<int>> ans;
    vector<int> temp;
    unordered_set<int> st;
    void solve(vector<int>& nums){
        if(temp.size() == n){ 
            ans.push_back(temp);
        }
        for(int i=0; i<n; i++){
            if(st.find(nums[i]) == st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(nums);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        solve(nums);
        return ans;
    }
};