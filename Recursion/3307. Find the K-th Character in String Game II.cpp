/*
using recursion 

tc: o(logk)
sc: o(logk)
*/

class Solution {
public:
    typedef long long ll;
    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        if(k == 1) return 'a';

        ll newK = -1;
        ll operationsType = -1;
        ll len = 1;

        for(int i=0; i<n; i++){
            len *= 2;
            if(len >= k){
                newK = k - len/2;
                operationsType = operations[i];
                break;
            }
        }

        char ch = kthCharacter(newK, operations);

        if(operationsType == 0) return ch;

        return ch == 'z' ? 'a' : ch+1;
    }
};