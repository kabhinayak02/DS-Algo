/*
using bit manipulation 

tc: o(n)
sc: o(1)
*/
class Solution {
public:

    long long minEnd(int n, int x) {
        long long cnt = 1;
        long long num = x+1;
        while(cnt != n){
            if((x & num) != x){
                num = (x | num);
                cnt++;
                if(cnt == n) return num;
            }
            else {
                cnt++;
                if(cnt == n) return num;
            }
            num++;
        }
        return x;
    }
};

/*
using bit manipulation 

tc: o(n)
sc: o(1)
*/
class Solution {
public:

    long long minEnd(int n, int x) {
        long long num = x;
        for(int i=1; i<n; i++){
            num = (num+1) | x;
        }
        return num;
    }
};

