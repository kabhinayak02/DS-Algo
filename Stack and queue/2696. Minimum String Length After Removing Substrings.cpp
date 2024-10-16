/*
using stack 

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    int minLength(string s) {
        int n = s.length();
        stack<char> st;
        for(int i=0; i<n; i++){
            if(!st.empty() && st.top() == 'A' && s[i] == 'B'){
                st.pop();
            }
            else if(!st.empty() && st.top() == 'C' && s[i] == 'D'){
                st.pop();
            }
            else{
                st.push({s[i]});
            }
        }
        return st.size();
    }
};

/*
Memory efficient solution

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    int minLength(string s) {
        int n = s.length();
        int i = 0;
        int j = 1;

        while(j < n){
            if(i < 0) {
                i++;
                s[i] = s[j];
            }
            else if((s[i] == 'A' && s[j] == 'B') || (s[i] == 'C' && s[j] == 'D')){
                i--;
            }
            else{
                i++;
                s[i] = s[j];
            }
            j++;
        }
        return i+1;
    }
};