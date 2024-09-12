/*

tc: o(2^n) 
sc: o(n)

*/

class Solution {
private: 
    void solve(int ind, int target, vector<int> &temp, vector<vector<int>> &ans, vector<int> &arr){
        if(ind == arr.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        // Pick the ind element
        if(arr[ind] <= target){ // check if the ind element should be smaller than target
            temp.push_back(arr[ind]);
            solve(ind, target-arr[ind], temp, ans, arr); // can pick same element multiple time
            temp.pop_back();
        }
        //not pick 
        solve(ind+1, target, temp, ans, arr);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, target, temp, ans, candidates);
        return ans;
    }
};