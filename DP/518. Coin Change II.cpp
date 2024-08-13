// Recursion + Memoisation
// tc: o(n*m) , n = coins.size, m = amount
// sc: o(n*m), 

class Solution {
public:
    int t[301][5001];
    int solve(int i, int amount, vector<int> &coins){
        if(i >= coins.size()) return 0;
        if(amount == 0) return 1;

        if(t[i][amount] != -1) return t[i][amount];

        int choose = 0, notChoose = 0;
        if(amount < coins[i]){
            return t[i][amount] = notChoose = solve(i+1, amount, coins);
        }
        notChoose = solve(i+1, amount, coins);
        choose = solve(i, amount-coins[i], coins);

        return t[i][amount] = choose + notChoose;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(t, -1, sizeof(t));
        return solve(0, amount, coins);
    }
};