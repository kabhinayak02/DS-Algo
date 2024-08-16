

// Using Max Heap (Priority Queue)
// tc: o(nlogn)
// sc: o(n)
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int a = INT_MAX, b = 0;

        priority_queue<pair<int,int>> pq;
        for(int i=0; i<n; i++){
            pq.push({arrays[i].back(), i});
        }
        int ma = 0;
        for(int i=0; i<n; i++){
            if(i != pq.top().second){
                ma = max(ma, pq.top().first - arrays[i][0]);
            }
            else{
                pair<int,int> temp = pq.top();
                pq.pop();
                ma = max(ma, pq.top().first - arrays[i][0]);
                pq.push(temp);
            }
        }
        return ma;
        
    }
};


// Approach 2
// tc: o(n)
// sc: o(1)
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int MIN = arrays[0].front();
        int MAX = arrays[0].back();

        int ans = 0;

        for(int i=1; i<n; i++){
            int currMin = arrays[i].front();
            int currMax = arrays[i].back();

            ans = max({ans, abs(currMin - MAX), abs(currMax - MIN)});

            MAX = max(MAX, currMax);
            MIN = min(MIN, currMin);
        }

        return ans;
    }
};