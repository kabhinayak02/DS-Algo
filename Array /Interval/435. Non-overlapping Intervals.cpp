/*

tc: o(nlogn)
sc: o(n)
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int cnt = 0;
        ans.push_back(intervals[0]);
        for(int i=1; i<n; i++){
            if(ans.back()[1] > intervals[i][0]){
                if(ans.back()[1] > intervals[i][1]){
                    ans.pop_back();
                    ans.push_back(intervals[i]);
                }
                cnt++;
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return cnt;
    }
};


/*

tc: o(n)
sc: o(1)
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int i = 0, j = 1;
        int cnt = 0;
        while(j < n){
            int a1 = intervals[i][0];
            int b1 = intervals[i][1];

            int a2 = intervals[j][0];
            int b2 = intervals[j][1];

            if(b1 <= a2){ // no overlapping
                i = j;
                j++;
            }
            else if(b1 <= b2){ // overlapping
                j++;
                cnt++;
            }
            else if(b1 > b2){ // overlapping
                i = j;
                j++;
                cnt++;
            }
        }
        return cnt;
    }
};


/*

tc: o(n)
sc: o(1)
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int i = 1;
        int cnt = 0;
        vector<int> last_intervals = intervals[0];
        while(i < n){
            int a1 = last_intervals[0];
            int b1 = last_intervals[1];

            int a2 = intervals[i][0];
            int b2 = intervals[i][1];

            if(b1 <= a2){ // no overlapping
                last_intervals = intervals[i];
                i++;
            }
            else if(b1 <= b2){ // overlapping
                i++;
                cnt++;
            }
            else if(b1 > b2){ // overlapping
                last_intervals = intervals[i];
                i++;
                cnt++;
            }
        }
        return cnt;
    }
};