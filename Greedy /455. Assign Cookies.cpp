/*
Greedy Approach 

trying to satisfy each child with the smallest possible cookie that can fulfill their greed factor.
So, sort both the array so that you can assign the cookie not more than required to the children.

tc: o(nlogn + mlogm + o(max(n, m)))
sc: o(1)
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0; // i -> children, j -> cookie
        
        while(j < m && i < n){
            if(g[i] <= s[j]){
                i++;
            }
            j++;
        }
        return i;
    }
};