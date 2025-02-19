/*
backtracking 

tc: o(3 * 2^(n-1)) * o(n)
sc: o(n * 2^n)
*/
class Solution {
    public:
        void solve(int n, string s, vector<string>& result){
            if(s.length() == n){
                result.push_back(s);
                return;
            }
    
            for(char ch: {'a', 'b', 'c'}){
                if(s.empty() || s.back() != ch){
                    solve(n, s+ch, result);
                }
            }
        }
        string getHappyString(int n, int k) {
            vector<string> result;
            solve(n, "", result);
            if (k > result.size()){
                return "";
            }
            return result[k - 1];
        }
    };


/*
backtracking 

tc: o(3 * 2^(n-1)) * o(n)
sc: o(n * 2^n)
*/
class Solution {
    public:
        void solve(int n, string s, vector<string>& result){
            if(s.length() == n){
                result.push_back(s);
                return;
            }

            for(char ch='a'; ch<='c'; ch++){
                if(!s.empty() && s.back() == ch) continue;

                s.push_back(ch);
                solve(n, s, result);
                s.pop_back();
            }
        }
        string getHappyString(int n, int k) {
            vector<string> result;
            solve(n, "", result);
            if (k > result.size()){
                return "";
            }
            return result[k - 1];
        }
    };


/*
backtracking : here in this code we sure that k > result.size() always or we always find the k'th string

tc: o(3 * 2^(n-1)) * o(n)
sc: o(n), system stack 

*/
class Solution {
    public:
        string solve(int n, int k, string s, int &cnt) {
            if (s.length() == n) {
                cnt++;
                if (cnt == k) {
                    return s;
                }
                return "";
            }
    
            vector<char> chars = {'a', 'b', 'c'};
            for (char c : chars) {
                if (s.empty() || s.back() != c) {
                    string res = solve(n, k, s + c, cnt);
                    if (!res.empty()) {
                        return res;
                    }
                }
            }
    
            return "";
        }
    
        string getHappyString(int n, int k) {
            int cnt = 0;
            return solve(n, k, "", cnt);
        }
    };