/*
Approach 1: Brute force

tc: o(n.n)
sc: o(1)
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int maxi = INT_MIN;
        int chunk = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, arr[i]);
            int mini = INT_MAX;
            for(int j=i+1; j<n; j++){
                mini = min(mini, arr[j]);
            }

            if(maxi < mini) chunk++;
        }
        return chunk;
    }
};

/*
Approach 2

tc: o(n+n+n)
sc: o(n)
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixMax(n), suffixMin(n);
        int maxi = arr[0];
        prefixMax[0] = maxi;
        for(int i=1; i<n; i++){
            maxi = max(maxi, arr[i]);
            prefixMax[i] = maxi;
        }

        int mini = arr[n-1];
        suffixMin[n-1] = mini;
        for(int i=n-2; i>=0; i--){
            mini = min(mini, arr[i]); 
            suffixMin[i] = mini;
        }

        int chunk = 0;
        for(int i=0; i<n; i++){
            int preMax =  i > 0 ? prefixMax[i-1] : -1;
            int suffMin = suffixMin[i];

            if(preMax < suffMin) chunk++;
        }
        return chunk;
    }
};

/*
Approach 2: most optimised 

use the fact that element in a array is always belongs to [0, n-1] so prefixSum of index and element 
should be same if they are sorted. 

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int idxSum = 0, eleSum = 0; 
        int chunk = 0;
        for(int i=0; i<n; i++){
            eleSum += arr[i];
            idxSum += i;

            if(eleSum == idxSum) chunk++;
        }
        return chunk;
    }
};