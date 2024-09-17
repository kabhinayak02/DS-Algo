/*

stores the count of element from nums in a map.

tc: o(n.n!)
sc: o(n) -> auxiliary space, o(n) ->  recursive stack
*/
class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void solve(unordered_map<int,int>& mp,  vector<int>& temp){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }
        for(auto [ele, frq]: mp){
            if(frq == 0){
                continue;
            }

            temp.push_back(ele);
            mp[ele]--;

            solve(mp, temp);

            temp.pop_back();
            mp[ele]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        unordered_map<int, int> freq;
        vector<int> temp;
        for(int &num: nums){
            freq[num]++;
        }
        solve(freq, temp);
        return ans;
    }
};

/*
Using swap 

tc: o(n)
sc: o(n)
*/

class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind, vector<int>& nums){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> uniqueSet;
        for(int i=ind; i<nums.size(); i++){
            if(uniqueSet.find(nums[i]) != uniqueSet.end()){
                continue;
            }
            
            uniqueSet.insert(nums[i]);
            swap(nums[ind], nums[i]);
           
            solve(ind+1, nums);

            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};