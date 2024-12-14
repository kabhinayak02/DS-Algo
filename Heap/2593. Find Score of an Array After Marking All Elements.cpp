/*
Brute force

tc: o(n.n)
sc: o(n)
*/
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        long long score = 0;

        for(int i=0; i<n; i++){
            int minVal = INT_MAX;
            int minIdx = -1;
            for(int j=0; j<n; j++){
                if(!visited[j] && nums[j] < minVal){
                    minVal = nums[j];
                    minIdx = j;
                }
                else if(!visited[j] && nums[j] == minVal){
                    minIdx = min(minIdx, j);
                }
            }
            if(minIdx == -1) break;
            score += nums[minIdx];
            visited[minIdx] = true;
            if(minIdx > 0) visited[minIdx - 1] = true;
            if(minIdx < n-1) visited[minIdx + 1] = true;
        }
        return score;
    }
};


/*
using vector sorting 

tc: o(nlogn)
sc: o(n)
*/
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> vec(n);

        for(int i=0; i<n; i++){
            vec[i] = {nums[i], i};
        }
        vector<bool> visited(n, false);
        sort(vec.begin(), vec.end());
        long long score = 0;
        for(int i=0; i<n; i++){
            int ele = vec[i].first;
            int idx = vec[i].second;
            if(!visited[idx]){
                visited[idx] = true;

                score += ele;

                if(idx-1 >= 0 && !visited[idx-1]) visited[idx-1] = true;
                if(idx+1 < n && !visited[idx+1]) visited[idx+1] = true;
            }

        }
        return score;
    }
};


/*
using min heap

tc: o(nlogn)
sc: o(n)
*/
class Solution {
public:
    #define P pair<int,int>
    long long findScore(vector<int>& nums) {
        int n = nums.size();

        vector<bool> visited(n, false);
        priority_queue<P, vector<P>, greater<P>> pq;
        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }
        long long score = 0;

        while(!pq.empty()){
            P temp = pq.top();
            int ele = temp.first;
            int idx = temp.second;  
            pq.pop();

            if(!visited[idx]){
                visited[idx] = true;

                score += ele;

                if(idx-1 >= 0 && !visited[idx-1]) visited[idx-1] = true;
                if(idx+1 < n && !visited[idx+1]) visited[idx+1] = true; 
            }
        }
        return score;
    }
};