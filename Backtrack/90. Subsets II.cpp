/*
tc: o(2^n)
sc: o(2^n)
*/
class Solution {
private:
    void solve(vector<int> &nums, int ind, vector<vector<int>> &ans, vector<int> &temp, bool prev){
        if(ind >= nums.size()){
            ans.push_back(temp);
            return;
        }
        solve(nums, ind+1, ans, temp, false); // ignore the ind'th element 
        if(ind > 0 && nums[ind] == nums[ind-1] && prev == false){ // prev == fales means prevs element is ignored. 
           return;  // if prev is ignored, ignore this ind'th element too. 
        }
        temp.push_back(nums[ind]);
        solve(nums, ind+1, ans, temp, true); // picked the ind'th element, and mark prev = true
        temp.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(nums, 0, ans, temp, false);
        return ans;
    }
};


/*

*/
class Solution {
private:
    void solve(vector<int> &nums, int ind, vector<vector<int>> &ans, vector<int> &temp){
        ans.push_back(temp);
        for(int i=ind; i<nums.size(); i++){
            if(i > ind && nums[i] == nums[i-1]) continue;

            temp.push_back(nums[i]);
            solve(nums, i+1, ans, temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(nums, 0, ans, temp);
        return ans;
    }
};