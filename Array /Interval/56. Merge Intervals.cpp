/*

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int j = 0;
        for(int i=1; i<n; i++){
            if(ans[j].back() >= intervals[i][0]){
                // ans[j][0] = min(ans[j][0], intervals[i][0]); // ignore this because we have sorted array
                ans[j][1] = max(ans[j][1], intervals[i][1]);
            }
            else{
                j++;
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

/*
commented 

tc: o(nlogn)
sc: o(1)

*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};

        // Sort intervals based on the starting value
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]); // Add the first interval to the answer
        
        for(int i = 1; i < intervals.size(); i++){
            // Check if the current interval overlaps with the last interval in the result
            if(ans.back()[1] >= intervals[i][0]) {
                // Merge the intervals by updating the end of the last interval
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else {
                // No overlap, add the current interval to the result
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};