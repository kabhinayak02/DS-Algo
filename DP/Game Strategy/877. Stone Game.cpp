
// tc: o(n^2)
// sc: o(n^2)
class Solution {
public: 
    int n;
    // i -> starting idx 0 (left)
    // j -> starting idx from n-1 (right)
    int t[501][501];
    int solve(vector<int>& piles, int i, int j){
        if(i > j) return 0;

        if(t[i][j] != -1) return t[i][j];

        if(i == j) return piles[i];


        /*
            That's how optimal game strategy works. Expect your opponent(Bob) to be playing optimally
            -When it's your turn, do your best
            -When it's your opponent's turn, expect the worst (that's why min() is taken below)
        */

        int chooseLeft = piles[i] + min(solve(piles, i+2, j), solve(piles, i+1, j-1));
        int chooseRight = piles[j] + min(solve(piles, i, j-2), solve(piles, i+1, j-1));

        return t[i][j] = max(chooseLeft, chooseRight);
    }
    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        memset(t, -1, sizeof(t));

        int sum = accumulate(piles.begin(), piles.end(), 0);
        int aliceScore = solve(piles, 0, n-1);
        return aliceScore > sum/2;
        
    }
};


/*
Same question on gfg: Optimal Strategy For A Game 
Link: https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1
*/

// Tabulation (Bottom - Up Approach)
class Solution{
    public:
    long long maximumAmount(int n, int arr[]){
        
        vector<vector<long long>> dp(n, vector<long long> (n, 0));
        
        for(long long i=n-1; i>=0; i--){
            for(long long j=0; j<n; j++){
                if(i > j){
                    dp[i][j] = 0;
                    continue;
                }
                long long chooseLeft = arr[i] + min((i+2 < n) ? dp[i+2][j] : 0, ((i+1 < n) && (j-1 >= 0)) ? dp[i+1][j-1] : 0);
                long long chooseRight = arr[j] + min((j-2 >= 0) ? dp[i][j-2] : 0, ((i+1 < n) && (j-1 >= 0)) ? dp[i+1][j-1] : 0);
                
                dp[i][j] = max(chooseLeft, chooseRight);
            }
        }
        return dp[0][n-1];
    }
};