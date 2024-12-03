/*
simple traversal 

tc: o(n+m)
sc: o(n) for storing the answer
*/
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        string ans = "";
        int idx = 0;
        for(int i=0; i<n; i++){
            int j;
            if(idx < spaces.size()) j = spaces[idx];
            if(i == j) {
                ans.push_back(' ');
                idx++;
            }
            ans += s[i];
        }
        return ans;
    }
};