/*

gfg link: https://www.geeksforgeeks.org/problems/attend-all-meetings/1

tc: o(nlogn)
sc: o(1)
*/
class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        for(int i=1; i<n; i++){
            if(arr[i][0] < arr[i-1][1]) return false;
        }
        return true;
    }
};