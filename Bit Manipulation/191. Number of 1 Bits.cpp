/*
using STL 

tc: o(1)
sc: o(1)
*/
class Solution {
public:
    int hammingWeight(int n) {
        return __builtin_popcount(n);
    }
};


/*
using bit manipulation  
tc: o(1)
*/
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n){
            n &= (n-1);
            count++;
        }
        return count;
    }
};


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            if(n&1 == 1){
                count++;
            }
            n = n>>1;
        }
        return count;
        
    }
};


