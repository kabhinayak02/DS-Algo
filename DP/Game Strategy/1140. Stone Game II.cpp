
/*
Problem Condition: 1 <= x <= 2M
This function is written for Alice. Where Alice try to choose optimal way
or try to choose best possible way to maximise the count of stones. 
Bob will always choose optimally to maximise their count. Always expect worst from Bob.
Worst means he will choose stones in a way that Alice always expect mini stones after Bob turn.
*/
// tc: o(n^3)
// sc: o(n^2)
class Solution {
public: 
    int n;
    int t[2][101][101];
    int solve(vector<int>& piles, int person, int i, int M){
        if(i >= n) return 0;

        if(t[person][i][M] != -1) return t[person][i][M];

        int result = (person == 1) ? -1: INT_MAX;

        int stones = 0;
        for(int x = 1; x <= min(2*M, n-i); x++){
            stones += piles[i+x-1];

            if(person == 1){ // If its Alice turn, Alice try to choose optmially and add to stones(count)
                result = max(result, stones + solve(piles, 0, i+x, max(M, x)));
            }
            
            else{ // If its Bob turn, expect worst from him, as he choose opmially to win his game
                result = min(result, solve(piles, 1, i+x, max(M, x)));
            }
        }
        return t[person][i][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(t, -1, sizeof(t));
        
        return solve(piles, 1, 0, 1);
    }
};