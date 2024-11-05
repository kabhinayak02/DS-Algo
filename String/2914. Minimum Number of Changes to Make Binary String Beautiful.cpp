/*

need observation that make smallest possible even length substring

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    int minChanges(string s) {
        int n = s.length(), cnt = 0;
        for(int i=1; i<n; i+=2){
            if(s[i] != s[i-1]){
                cnt++;
            }
        }
        return cnt;
    }
};