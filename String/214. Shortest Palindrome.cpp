/*
MLE

this code accepted in java, need space improvement for c++

tc: o(n^2)
sc: o(n)

*/
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s.substr(0, n-i) == rev.substr(i)){
                return rev.substr(0, i) + s;
            }
        }
        return rev + s;
    }
};

/*
Using memcmp

tc: o(n^2)
sc: o(1)

*/
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.length();
        for(int i=0; i<n; i++){
            if(memcmp(s.c_str(), rev.c_str()+i, n-i) == 0){
                return rev.substr(0, i) + s;
            }
        }
        return rev + s;
    }
};