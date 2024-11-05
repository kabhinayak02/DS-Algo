/*
using 2 loop 

we assume i'th index as a peek now, iterate left and right of i'th index with valid assumptions  

tc: o(n.n)
sc: o(n)
*/

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int n = heights.size();
        long long cnt = 0;


        for(int i=0; i<n; i++){
            long long ans = 0;
            vector<int> temp = heights;

            // Calculate sum to the left of index i
            for(int j=i; j>=0; j--){
                if(j > 0 && temp[j] < temp[j-1]){
                    temp[j-1] = temp[j];
                }
                ans += temp[j];
            }

            // Calculate sum to the right of index i
            for(int j=i+1; j<n; j++){
                if(temp[j] > temp[j-1]){
                    temp[j] = temp[j-1];
                }
                ans += temp[j];
            }
            cnt = max(cnt, ans);
        }
        return cnt;
    }
};