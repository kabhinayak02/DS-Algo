/*
Brute force using 2 loop 

tc: o(n.n)
sc: o(1)
*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int a = values[i] + i;
            for(int j=i+1; j<n; j++){
                int b = values[j] - j;
                ans = max(ans, a + b);
            }
        }
        return ans;
    }
};


/*
using greedy 

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = 0;
        int maxiLeft = values[0] + 0;
        for(int j=1; j<n; j++){
            int a = values[j-1] + (j-1);
            maxiLeft = max(maxiLeft, a);

            int b = values[j] - j;
            ans = max(ans, maxiLeft + b);
        }
        return ans;
    }
};