/*
using stack 

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(char &ch: s){
            if(ch == '['){
                st.push(ch);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        return (st.size()+1)/2;
    }
};


/*
without using stack 

we only need size or swap only, so we can directly count it.

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    int minSwaps(string s) {
        int size = 0;
        for(char &ch: s){
            if(ch == '['){
                size++;
            }
            else if(size > 0){
                size--;
            }
        }
        return (size+1)/2;
    }
};