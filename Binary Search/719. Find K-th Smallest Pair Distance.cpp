#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Brute Force (TLE)
// tc: o(n^2logk)
// sc: o(k)
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int diff = abs(nums[i]-nums[j]);
                pq.push(diff);
                if(pq.size() > k) pq.pop();
            }
        }
        return pq.top();
    }
};

/*
Approach 2
tc: o(n^2)
sc: o(maxEle), worst case: o(n)
*/
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());
        vector<int> vec(maxEle+1, 0);
        // Create a vector vec where vec[d] stores the count of pairs that have dist d

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int d = abs(nums[i] - nums[j]);
                vec[d]++;
            }
        }

        // Now iterate the vector vec[] and find the kth smallest dist. 
        for(int d=0; d<maxEle+1; d++){
            k -= vec[d];
            if(k <= 0){
                return d;
            }
        }

        return -1;
    }
};


// Using with nth_element (only work for C++)
// tc: avg. o(n), worst: o(n^2)
// sc: o(n^2)
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> vec(n*(n-1)/2);

        int idx = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int d = abs(nums[i] - nums[j]);
                vec[idx] = d;
                idx++;
            }
        }

        nth_element(vec.begin(), vec.begin() + (k-1), vec.end());
        return vec[k-1];
    }
};


// Using Binary Search and Sliding Window (Most efficient)
// tc: o(nlogn)
// sc: o(1)
class Solution {
public:
    // Sliding Window + Binary Search
    int solve(vector<int>& nums, int d){
        int i = 0, j = 1, n = nums.size(), pairCount = 0;
        while(j < n){
            while(nums[j] - nums[i] > d){
                i++;
            }
            pairCount += (j-i);
            j++;
        }
        return pairCount;
    } 
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int l = 0;
        int r = nums[n-1] - nums[0];
        int ans = 0;

        while(l <= r){
            int mid = l + (r-l)/2;

            int countPair = solve(nums, mid);

            if(countPair < k){
                l = mid + 1;
            }
            else{
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
};