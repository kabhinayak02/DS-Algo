// gfg link: https://www.geeksforgeeks.org/problems/aggressive-cows/1
/*
using binary search 

implement binary search on given possible range of answer
check if possible maxi. dist. (mid) is possible to place for cows if yes, move the binary search to greater mid 

tc:
sc:

*/
class Solution {
  public:
    int isPossible(vector<int>& stalls, int mid, int k){
        int n = stalls.size();
        int cow = 1, lastCowPosition = stalls[0];
        for(int i=0; i<n; i++){
            if(stalls[i] - lastCowPosition >= mid){
                cow++;
                lastCowPosition = stalls[i];
            }
            if(cow >= k){
                return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int l = 0, h = stalls[n-1] - stalls[0];
        int ans = -1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(isPossible(stalls, mid, k)){
                ans = mid;
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return ans;
    }
};