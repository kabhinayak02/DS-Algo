// tc: o(n)
// sc: o(n)
class Solution {
public: 
    int n;
    int t[50001];
    int solve(int i, vector<int>& stoneValue){
        if(i >= n) return 0;

        if(t[i] != -1) return t[i];

        int result = stoneValue[i] - solve(i+1, stoneValue);

        if(i+1 < n){
            result = max(result,  stoneValue[i] + stoneValue[i+1] - solve(i+2, stoneValue));
        }
    
        if(i+2 < n){
            result = max(result,  stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - solve(i+3, stoneValue));
        }
          
        return t[i] = result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        memset(t, -1, sizeof(t));

        int diff = solve(0, stoneValue);

        if(diff > 0) return "Alice";
        else if(diff < 0) return "Bob";

        return "Tie";
    }
};

/*
Bottom Up 
tc: o(n)
sc: o(n)

Converting above top-down approach to bottom-up approach. 
Here we are traversing from right to left (idx: n-1 to 0), so our final answer is stores in t[0] not t[n]

*/

class Solution {
public: 
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> t(n+1, 0);

        for(int i=n-1; i>=0; i--){

            t[i] = stoneValue[i] - t[i+1];

            if(i+2 <= n){
                t[i] = max(t[i], stoneValue[i] + stoneValue[i+1] - t[i+2]);
            }
            if(i+3 <= n){
                t[i] = max(t[i], stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - t[i+3]);
            }
        }

        int diff = t[0];

        if(diff > 0) return "Alice";
        else if(diff < 0) return "Bob";

        return "Tie";
    }
};


/*
Space optimised, Bottom-up 

We can observe in the above bottom-up code that we only need 3 previous states. 
So instead of maintaining the entire n-size vector, we can only use 3 variables. 

tc: o(n)
sc: o(1)
*/
class Solution {
public: 
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        int a = 0; // t[i+1]
        int b = 0; // t[i+2]
        int c = 0; // t[i+3]

        for(int i=n-1; i>=0; i--){

            int result = INT_MIN;

            result = max(result, stoneValue[i] - a); 

            if(i+2 <= n){
                result = max(result, stoneValue[i] + stoneValue[i+1] - b);
            }
            if(i+3 <= n){
                result = max(result, stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - c);
            }
            c = b;
            b = a;
            a = result;
        }

        int diff = a;

        if(diff > 0) return "Alice";
        else if(diff < 0) return "Bob";

        return "Tie";
    }
};