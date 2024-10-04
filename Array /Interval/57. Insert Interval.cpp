/*
using sorting

tc: o(nlogn)
sc: o(n)
*/
class Solution {
private:
    bool checkOverlap(int a1, int b1, int a2, int b2){
        return max(a1, a2) <= min(b1, b2);
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n == 0) return {newInterval};
        vector<bool> checkForOverlap(n, false);

        int flag = 0;
        for(int i=0; i<n; i++){
            if(checkOverlap(intervals[i][0], intervals[i][1], newInterval[0], newInterval[1])){
                checkForOverlap[i] = true;
                flag = 1;
            }
        }
        if(flag == 0){
            intervals.push_back(newInterval);
            sort(intervals.begin(), intervals.end());
            return intervals;
        }
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(checkForOverlap[i] == true){
                int j = i;
                int start = min(intervals[i][0], newInterval[0]);
                while(j < n && checkForOverlap[j] == true){
                    j++;
                }
                int end = 0;
                if(checkForOverlap[j] == true){
                    end = max(intervals[j][1], newInterval[1]);
                    break;
                } 
                else if(checkForOverlap[j-1] == true){
                    end = max(intervals[j-1][1], newInterval[1]);
                    i = j-1;
                } 

                ans.push_back({start, end});
            }
            else{
                ans.push_back(intervals[i]);
            }
            

        }
        return ans;
    }
};

/*

tc: o(nlogn)
sc: o(1)
*/
class Solution {
private:
    bool checkOverlap(int a1, int b1, int a2, int b2) {
        return max(a1, a2) <= min(b1, b2);
    }

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if (n == 0) return {newInterval};

        int flag = 0;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            // Check if current interval overlaps with newInterval
            if (checkOverlap(intervals[i][0], intervals[i][1], newInterval[0], newInterval[1])) {
                flag = 1;
                int j = i;
                // Find start of the merged interval
                int start = min(intervals[i][0], newInterval[0]);
                
                // Merge all overlapping intervals
                while (j < n && checkOverlap(intervals[j][0], intervals[j][1], newInterval[0], newInterval[1])) {
                    j++;
                }
                
                // Calculate the end of the merged interval
                int end = max(intervals[j-1][1], newInterval[1]);
                
                // Add the merged interval
                ans.push_back({start, end});
                
                // Skip the merged intervals
                i = j - 1;
            } else {
                ans.push_back(intervals[i]);
            }
        }
        
        // If no overlap was found, add newInterval at the correct place
        if (flag == 0) {
            ans.push_back(newInterval);
            sort(ans.begin(), ans.end());
        }
        
        return ans;
    }
};

/*
without using sorting 

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;

        // Add all intervals that come before the new interval
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

        // Merge all overlapping intervals
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        // Add the merged interval
        ans.push_back(newInterval);

        // Add all the remaining intervals
        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};