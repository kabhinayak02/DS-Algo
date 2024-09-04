/*
[Brute force]

tc: o(n)
sc: o(1)
*/
class Solution {
    public:
        int findXOR(int l, int r) {
            int ans = 0;
            for(int i = l; i <= r; i++){
                    ans ^= i;
            }
            return ans;
        }
};

/*

tc: o(1)
sc: o(1)
*/
class Solution {
  public:
    int f(int n){
        
        if(n % 4 == 1) return 1;
        if(n % 4 == 2) return n + 1;
        if(n % 4 == 3) return 0;
        else return n;
        
    }
    int findXOR(int l, int r) {
        return f(l - 1) ^ f(r); // same no. xor is 0.
    }
};