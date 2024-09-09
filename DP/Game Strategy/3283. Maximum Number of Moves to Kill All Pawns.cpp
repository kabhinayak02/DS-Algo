/*
DP + Bitmasking + Precomputation using BFS
precompute the minDist data and use it to solve the game strategy using dp. 

tc: O(n * 2^n * n)
sc: O(n * 2^n)
*/
class Solution {
public:
    // directions for knight moves
    vector<vector<int>> directions = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    void bfs(int x, int y, int index, vector<vector<int>>& minDist, vector<vector<int>>& pos){
        vector<vector<int>> t(50, vector<int> (50, -1));
        queue<pair<int,int>> q;
        q.push({x, y});
        t[x][y] = 0;

        while(!q.empty()){
            auto [currX, currY] = q.front();
            q.pop();

            for(auto &dir: directions){
                int newX = currX + dir[0];
                int newY = currY + dir[1];

                if(newY >= 0 && newX >= 0 && newX < 50 && newY < 50 && t[newX][newY] == -1){
                    t[newX][newY] = t[currX][currY] + 1;
                    q.push({newX, newY});
                }
            }
        }

        for(int i=0; i<pos.size(); i++){
            int x_ = pos[i][0];
            int y_ = pos[i][1];

            minDist[index][i] = t[x_][y_]; // fill the required one in minDist.
        }
    }
    int dp[51][1 << 15][2];
    int solve(vector<vector<int>>& minDist, int idx, int mask, int n, bool alice){
        if(mask == 0) return 0; // mask = 0 means we consume all the pawn 

        if(dp[idx][mask][alice] != -1) return dp[idx][mask][alice];

        int result = (alice == true) ? -1 : 1e9; // if alice turn its -1 else 1e9 for bob.

        for(int i=1; i<n; i++){ // n -> pos.size(), first element in pos is knight, so we start with i = 1;
            if(mask & (1 << (i-1))){ // check if pawn is available, 1 for yes, 0 for not.
                int moves = minDist[idx][i]; // moves need to move knight to pawn.

                if(alice){  // alice turn, alice try to win game so choose maximum moves.
                    result = max(result, moves + solve(minDist, i, mask ^ (1 << (i-1)), n, !alice));
                }
                else{ // bob turn, bob try to win his game, so he choose maximum for himself but left minimum for us.
                    result = min(result, moves + solve(minDist, i, mask ^ (1 << (i-1)), n, !alice));
                }
            }
        }
        return dp[idx][mask][alice] = result;
    }
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n = positions.size();

        vector<vector<int>> pos; // creating new vector including knight.
        pos.push_back({kx, ky});
        for(auto &vec: positions){
            pos.push_back({vec[0], vec[1]});
        }

        vector<vector<int>> minDist(n+1, vector<int>(n+1, 0)); // distance of [knight or pawn,to pawn]

        for(int i=0; i<pos.size(); i++){
            int x = pos[i][0];
            int y = pos[i][1];
            bfs(x, y, i, minDist, pos); // find the minDist including knight position
        }

        bool alice = true; // game start with alice 
        memset(dp, -1, sizeof(dp));
        return solve(minDist, 0, (1<<n)-1, pos.size(), alice);
    }
};