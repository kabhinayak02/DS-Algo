/*
using counting freq 

tc: o(n)
sc: o(26)
*/
class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n == k){
            return true;
        }

        if(n < k){
            return false;
        }
        vector<int> freq(26, 0);

        for(char &ch: s){
            freq[ch-'a']++;
        }
        int odd = 0;
        for(int i=0; i<26; i++){
            if(freq[i]%2 != 0){
                odd++;
            }
        }

        if(odd > k) return false;
        return true;
    }
};