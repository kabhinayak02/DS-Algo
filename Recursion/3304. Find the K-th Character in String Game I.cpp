/*
using recursion

tc: o(logk)
sc: o(logk)
*/
class Solution {
public:
    char kthCharacter(int k) {
        if(k == 1) return 'a';
        int len = 1;
        int newK = -1;
        while(true){
            len *= 2;
            if(len >= k){
                newK = k - len/2;
                break;
            }
        }

        char ch = kthCharacter(newK);

        return ch + 1;
    }
};