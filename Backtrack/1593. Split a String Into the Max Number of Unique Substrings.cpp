/*
using backtracking

In the end of the each recursive call we will get the unique string in the set, so size of the set gives the 
number of ans. 

tc: o(2^n)
sc: o(n)
*/

class Solution {
public:
    void solve(int idx, int n, int &ans, string &s, set<string>& st){
        if(idx == n){
            ans = max(ans, (int)st.size());
            return;
        }
        for(int j=idx; j<n; j++){
            string str = s.substr(idx, j-idx+1);
            if(!st.count(str)){
                st.insert(str);
                solve(j+1, n, ans, s, st);
                st.erase(str);
            }
        }
    }
    int maxUniqueSplit(string s) {
        int n = s.length();
        int ans = 1;
        set<string> st;

        solve(0, n, ans, s, st);
        return ans; 
    }
};


/*
using backtracking with optimisation 

tc: o(2^n)
sc: o(n)
*/
class Solution {
public:
    void solve(int idx, int n, int &ans, string &s, set<string>& st){
        if((int)st.size() + (n - idx) <= ans) return;

        if(idx >= n){
            ans = max(ans, (int)st.size());
            return;
        }
        for(int j=idx; j<n; j++){
            string str = s.substr(idx, j-idx+1);
            if(!st.count(str)){
                st.insert(str);
                solve(j+1, n, ans, s, st);
                st.erase(str);
            }
        }
    }
    int maxUniqueSplit(string s) {
        int n = s.length();
        int ans = 1;
        set<string> st;

        solve(0, n, ans, s, st);
        return ans; 
    }
};