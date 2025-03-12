/*
using sliding window 

add all the valid sub-string before moving the i'th pointer i.e. ans += (n-j)

tc: o(n)
sc: o(3)
*/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        int i = 0, j = 0;
        int ans = 0;
        while(j < n){
            mp[s[j]]++;
            while(i <= j && mp.size() == 3){ // imp
                ans += (n-j);
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};