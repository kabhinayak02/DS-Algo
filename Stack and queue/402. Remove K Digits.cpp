/*
Using stack 

Try to remove high order place value and remaining number should be increasing 

tc: o(n)
sc: o(n)

*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        if(num.size() == k) return "0";
        for(auto i: num){
            while(!st.empty() && i < st.top() && k > 0){
                st.pop();
                k--;
            }
            st.push(i);
        }

        while(!st.empty() && k>0){
            k--;
            st.pop();
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++){
            if(ans[i]!='0'){
                return ans = ans.substr(i);
            }
        }
        return "0";
        
    }
};

/*
Using string instead of stack 

tc: o(n)
sc: o(n)

*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        string ans = "";
        for(int i=0; i<n; i++){
            while(ans.length() > 0 && ans.back() > num[i] && k > 0){
                ans.pop_back();
                k--;
            }

            if(ans.length() > 0 || num[i] != '0'){
                ans.push_back(num[i]); // to avoid the case of leading 0
            }
        }

        while(ans.length() > 0 && k > 0){
            ans.pop_back();
            k--;
        }
        if(ans == "") return "0";
        return ans;
    }
};

