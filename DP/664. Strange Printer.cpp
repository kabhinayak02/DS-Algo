
/*
tc: o(n^3)
sc: o(n^2)
*/
/*
We use left(l) = 0 and right(r) = n-1 pointer. Also we have a case where s = "aba" and "abaaaaa" to handle. 
So we need one more pointer (i) which start with i = l+1, to check how many same char we are getting from start, 
because we count it as 1. But here is the case like in "aba" we can print "aaa" first and then change mid "a" to b, 
ans we will get "aba" in 2 steps which is opmtimised answer. 
How we can handle this?

ex 1:
a  b  a
l  i  r

ex 2:
i -> is the fist char which is not equal to s[l]. So thats mean char from l to i is same and we count it as 1. 

a  a  a  b  a
l        i  r


ex 3:
a  b  a  a  a  a
l  i           r
   j

In this case we need one more pointer (j) so that we count that how many we are going to get char s[l] after b or idx i (j = i). 
Because we will going to count it as 1 as printer can print all s[l] in one go.

So we need a loop to traverse the remaining s to check with the s[l] after j.

a  b  a  a  a  a
l  i           r
               j

*/
class Solution {
public:
    int n;
    int t[101][101];
    int solve(int l, int r, string &s){
        if(l == r) return 1;

        if(t[l][r] != -1) return t[l][r];

        if(l > r) return 0;

        /*
        Traverse same char from starting without break.
        */
        int i = l+1;
        while(i <= r && s[i] == s[l]){
            i++;
        }

        /*
        If i = r + 1 means we found all the same char, so printer can print in one go.
        */
        if(i == r+1){
            return 1;
        }

        int basic = 1 + solve(i, r, s);

        /*
        Handle cases like s = "aba" and "abaaaaaa"
        */
        int otherWay = INT_MAX;
        // We need a loop to traverse all the 'a' after b 
        for(int j=i; j<=r; j++){
            if(s[j] == s[l]){
                int otherWayTemp = solve(i, j-1, s) + solve(j, r, s);
                otherWay = min(otherWay, otherWayTemp);
            }
        }
        return t[l][r] = min(otherWay, basic);
    }
    int strangePrinter(string s) {
        n = s.length();
        memset(t, -1, sizeof(t));

        return solve(0, n-1, s);
    }
};



/*
Same Approach but with different way 

*/
class Solution {
public:
    int n;
    int t[101][101];
    int solve(int l, int r, string &s){
        if(l == r) return 1;

        if(t[l][r] != -1) return t[l][r];
        
        int ans;
        if(s[l] == s[r] || s[r-1] == s[r]) {
            ans = solve(l, r-1, s);
        }
        else if(s[l] == s[l+1]){
            ans = solve(l+1, r, s);
        }
        else{
            /*
            We cann't move left pointer (i.e. solve(l+1, r, s)) because we always try to find 
            same char s[l] and s[r], so that printer can directly print from l to r in one go. So eliminate
            from the back side of the array. Also we handle the case above is s[r] == s[r-1] for example like 
            s = "acdbbbbb" 
            */
            ans = 1 + solve(l, r-1, s); 
            for(int k=l+1; k<r; k++){
                if(s[k] == s[r]){
                    ans = min(ans, solve(l, k-1, s) + solve(k, r-1, s));
                }
            }
        }
        return t[l][r] = ans;
    }
    int strangePrinter(string s) {
        n = s.length();
        memset(t, -1, sizeof(t));

        return solve(0, n-1, s);
    }
};