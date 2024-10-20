/*
using stack 

tc: o(n)
sc: o(n)
*/
class Solution {
private:
    char solve(vector<char> &temp, char op){
        bool ele1 = (temp[0] == 't');
        if(op == '!'){
            ele1 = !ele1;
        }
        if(op == '&'){
            for(int i=1; i<temp.size(); i++){
                ele1 &= (temp[i] == 't');
            }
        }else{
            for(int i=1; i<temp.size(); i++){
                ele1 |= (temp[i] == 't');
            }
        }
        return (ele1 == false) ? 'f' : 't';
    }
public:
    bool parseBoolExpr(string exp) {
        int n = exp.length();
        stack<char> st;
        for(int i=0; i<n; i++){
            if(exp[i] == ')'){
                vector<char> temp;
                while(!st.empty() && st.top() != '('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();

                char pushToStack = solve(temp, op);
                st.push(pushToStack);
                
            }
            else{
                if(exp[i] == ',') continue;
                st.push(exp[i]);
            }
        }
        return (st.top() == 't');
    }
};