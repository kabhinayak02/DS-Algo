
// tc: o(n*m)
// sc: o(n*m)
class Solution {
  public:
    int t[1001][1001];
    int maxi = 0;
    int solve(int i, int j, string &s1, string &s2){
        if(i >= s1.size() || j >= s2.size()) return 0;
        
        if(t[i][j] != -1) return t[i][j];
        
        if(s1[i] == s2[j]){
            t[i][j] = 1 + solve(i+1, j+1, s1, s2);
            maxi = max(maxi, t[i][j]);
        }
        else{
            t[i][j] = 0;
        }
        
        solve(i+1, j, s1, s2);
        solve(i, j+1, s1, s2);
        return t[i][j];
    }
    int longestCommonSubstr(string str1, string str2) {
        memset(t, -1, sizeof(t));
        solve(0 ,0, str1, str2);
        return maxi;
    }
};