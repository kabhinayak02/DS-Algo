/*
using priority queue

first sort the array with arrival time and use the min heap to stores the departure time of that intervals whenever
you get the interval with arrival time greater than the departure time pop the element and push the new depart time
or else push the new departure time without popping 
size of the pq give the groups 

tc: o(nlogn)
sc: o(n)
*/

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for(vector<int>& interval: intervals){
            int start = interval[0];
            int end = interval[1];

            if(!pq.empty() && start > pq.top()){
                pq.pop();
            }
            pq.push(end);
        }
        return pq.size();
    }
};