/*
using stack 

tc: o(n)
sc: o(n)
*/
class Solution {
  public:
    int maxLength(string& S) {
        int maxLen = 0;
        stack<int> stk;
        stk.push(-1); // Initialize with -1 to handle cases where the first character is ')'

        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (!stk.empty()) {
                    maxLen = max(maxLen, i - stk.top());
                } else {
                    stk.push(i); // If the stack becomes empty, push the current index as the new starting point
                }
            }
        }

        return maxLen;
    }
};