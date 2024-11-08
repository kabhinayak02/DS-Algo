/*
gfg link: https://www.geeksforgeeks.org/problems/minimum-times-a-has-to-be-repeated-such-that-b-is-a-substring-of-it--170645/1

string searching 

tc: o(n)
sc: o(n)
*/

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        string rep = s1;
        int cnt = 1;
        while(s1.size() < s2.size()){
            s1 += rep;
            cnt++;
        }
        if(s1.find(s2) != -1) return cnt;
        s1 += rep;
        cnt++;
        if(s1.find(s2) != -1) return cnt;
        return -1;
        
    }
};


class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        string rep = "";
        int cnt = 0;
        while(rep.size() <= 2 * s2.size()){
            rep += s1;
            cnt++;
            if(rep.find(s2) != -1) return cnt;
        }
        return -1;
    }
};