/*
without using stack 

can be done using stack, but we need count only so we can eliminate stack 

*/
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int open = 0, close = 0;
        for(char &ch: s){
            if(ch == '('){
                open++;
            }
            else if(ch == ')' && open > 0){
                open--;
            }
            else{
                close++;
            }
        }
        return open + close;
    }
};