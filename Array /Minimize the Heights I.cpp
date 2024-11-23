/*

gfg link: https://www.geeksforgeeks.org/problems/minimize-the-heights-i/1

*/
class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int d = arr[n-1]-arr[0];
        int maxi = arr[n-1];
        int mini = arr[0];
        for(int i=1; i<n; i++){
            maxi = max(arr[i-1]+k, arr[n-1]-k);
            mini = min(arr[0]+k, arr[i]-k);
            
            d = min(d, maxi-mini);
        }
        return d;
    }
};