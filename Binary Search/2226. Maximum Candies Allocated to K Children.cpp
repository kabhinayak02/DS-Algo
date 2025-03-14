/*
brute force

tc: o(n.n)
sc: o(1)
*/
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int maxC = 0;
        for(int i=0; i<n; i++){
            maxC = max(maxC, candies[i]);
        }

        for(int i=maxC; i>=1; i--){
            long long count = 0;
            for(int j=0; j<n; j++){
                count += (candies[j]/i);
            }

            if(count >= k){
                return i;
            }
        }
        return 0;
    }
};


/*
using binary search


tc: o(log(maxC))
sc: o(1)
*/
class Solution {
public:
    bool canDist(vector<int>& candies, int mid, long long k){
        int n = candies.size();
        long long count = 0;
        for(int i=0; i<n; i++){
            count += (candies[i]/mid);
            if(count >= k){
                return true;
            }
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int maxC = 0;
        for(int i=0; i<n; i++){
            maxC = max(maxC, candies[i]);
        }

        int l = 1;
        int r = maxC;
        int ans = 0;
        while(l <= r){
            int mid = l + (r-l)/2;

            if(canDist(candies, mid, k)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};