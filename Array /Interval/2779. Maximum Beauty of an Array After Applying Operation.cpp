/*

tc: o(nlogn)
sc: o(n)
*/
class Solution {
public:
    #define P pair<int,int>
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<P> intervals(n);

        for(int i=0; i<n; i++){
            intervals[i] = {nums[i]-k, nums[i]+k};
        }
        sort(intervals.begin(), intervals.end());

        deque<P> deq;
        int maxBeauty = 0;
        for(P interval: intervals){

            while(!deq.empty() && deq.front().second < interval.first){
                deq.pop_front();
            }
            deq.push_back(interval);
            maxBeauty = max(maxBeauty, (int)deq.size());
        }
        return maxBeauty;
    }
};

/*
change in deque

tc: o(nlogn)
sc: o(n)
*/
class Solution {
public:
    #define P pair<int,int>
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<P> intervals(n);

        for(int i=0; i<n; i++){
            intervals[i] = {nums[i]-k, nums[i]+k};
        }
        sort(intervals.begin(), intervals.end());

        deque<int> deq; // can work only with index instead of pairs 
        int maxBeauty = 0;
        for(P interval: intervals){

            while(!deq.empty() && deq.front() < interval.first){
                deq.pop_front();
            }
            deq.push_back(interval.second);
            maxBeauty = max(maxBeauty, (int)deq.size());
        }
        return maxBeauty;
    }
};

/*
using queue

tc: o(nlogn)
sc: o(n)
*/
class Solution {
public:
    #define P pair<int,int>
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<P> intervals(n);

        for(int i=0; i<n; i++){
            intervals[i] = {nums[i]-k, nums[i]+k};
        }
        sort(intervals.begin(), intervals.end());

        queue<int> que;
        int maxBeauty = 0;
        for(P interval: intervals){

            while(!que.empty() && que.front() < interval.first){
                que.pop();
            }
            que.push(interval.second);
            maxBeauty = max(maxBeauty, (int)que.size());
        }
        return maxBeauty;
    }
};

/*
using sorting and binary search

y <= x + 2*k is imp. remember the derivation 
overlapping condition: (x - k) >= (y + k)

tc: o(nlogn) 
sc: o(n)
*/
class Solution {
public:
    int binarySearch(vector<int>& nums, int target){
        int ans = 0;
        int l = 0, r = nums.size()-1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] <= target){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int maxBeauty = 0;
        for(int i=0; i<n; i++){
            int x = nums[i];
            int y = x + 2*k;

            int index = binarySearch(nums, y);

            maxBeauty = max(maxBeauty, index-i+1);
        }
        return maxBeauty;
    }
};

/*
using sliding window 


tc: o(nlogn)
sc: o(1)
*/
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0, j = 0;
        int maxBeauty = 0;
        
        while(i < n){
            while(j < n && nums[j] <= nums[i] + 2*k){
                j++;
            }
            maxBeauty = max(maxBeauty, j-i);
            i++;
        }
        return maxBeauty;
    }
};


/*
using recursion and binary search 

tc: o(n.n)
sc: o(n) recursive stack 
*/
class Solution {
public:
    int n;
    int binarySearch(vector<vector<int>>& events, int endTime){
        int l = 0, r = n-1;
        int ans = n;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(events[mid][0] > endTime){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    int solve(vector<vector<int>>& events, int i, int count){
        if(count == 2 || i >= n){
            return 0;
        }
        
        int nextValidIndex = binarySearch(events, events[i][1]);
        int take = events[i][2] + solve(events, nextValidIndex, count+1);
        int not_take = solve(events, i+1, count);

        return max(take, not_take);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(), events.end());
        int count = 0;
        return solve(events, 0, count);
    }
};


/*
using dp memoisation 

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    int n;
    int binarySearch(vector<vector<int>>& events, int endTime){
        int l = 0, r = n-1;
        int ans = n;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(events[mid][0] > endTime){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    int dp[100001][3];
    int solve(vector<vector<int>>& events, int i, int count){
        if(count == 2 || i >= n){
            return 0;
        }
        if(dp[i][count] != -1) {
            return dp[i][count];
        } 
        int nextValidIndex = binarySearch(events, events[i][1]);
        int take = events[i][2] + solve(events, nextValidIndex, count+1);
        int not_take = solve(events, i+1, count);

        return dp[i][count] = max(take, not_take);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        memset(dp, -1, sizeof(dp));

        sort(events.begin(), events.end());
        int count = 0;
        return solve(events, 0, count);
    }
};