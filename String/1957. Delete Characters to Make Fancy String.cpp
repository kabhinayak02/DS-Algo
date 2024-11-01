/*
using pointers

tc: o(n)
sc: o(n) ans
*/
class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string ans = "";
        ans += s[0];
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(s[i-1] == s[i]){
                cnt++;
            }
            else{
                cnt = 1;
            }
            if(cnt < 3){
                ans += s[i];
            }
        }
        return ans;
    }
};