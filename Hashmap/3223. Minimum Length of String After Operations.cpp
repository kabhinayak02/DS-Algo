/*
2 pass

Observe the pattern of removal, take some example by yourself

tc: o(n+n)
sc: o(n)
*/
class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;

        for(auto &ch: s){
            mp[ch]++;
        }
        int count = 0;
        for(auto &[ch, ele] : mp){
            if(ele%2 == 0) count+=2;
            else count += 1;
        }
        return count;
    }
};