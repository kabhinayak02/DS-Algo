/*
Using Backtracking 

tc: o(4^n)
sc: o(n.4^n)
*/
class Solution {
void solve(int ind, string &digits, unordered_map<char, string> &mp, string &temp, vector<string> &ans){
    if(ind == digits.size()){
        ans.push_back(temp);
        return;
    }

    char ch = digits[ind];
    string str = mp[ch];
    for(int i=0; i<str.length(); i++){
        temp.push_back(str[i]);
        solve(ind+1, digits, mp, temp, ans);
        temp.pop_back();
    }
}
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> ans;
        string temp = "";
        
        solve(0, digits, mp, temp, ans);
        return ans;
    }
};