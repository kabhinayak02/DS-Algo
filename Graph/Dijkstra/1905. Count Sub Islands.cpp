/*
Using DFS 

tc: o(n*m)
sc: o(n*m) recursion 
*/
class Solution {
public:
    int n, m;
    bool dfs(int row, int col, vector<vector<int>>& grid1, vector<vector<int>>& grid2,  vector<vector<bool>> &vis){
        vis[row][col] = true;

        bool ans = true;
        if (grid1[row][col] != 1) {
            ans = false;
        }
        
        int delRow[4] = {0, 1, 0, -1};
        int delCol[4] = {-1, 0, 1, 0};
        for(int i=0; i<4; i++){
            int nr = row + delRow[i];
            int nc = col + delCol[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid2[nr][nc] == 1 && !vis[nr][nc]) {
                
                if(!dfs(nr, nc, grid1, grid2, vis)) {
                    ans = false;
                }
            }
        }
        return ans;

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();

        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j] == 1 && !vis[i][j]) {
                    if(dfs(i, j, grid1, grid2, vis)) {  // Start DFS from the current (i, j) position
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};


/*
Using DFS
2nd way 

tc: o(n*m)
sc: o(n*m) recursion 
*/
class Solution {
public:
    int n, m;
    bool dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if(i < 0 || i == n || j < 0 || j == m) return true;

        if(grid2[i][j] != 1) return true;

        grid2[i][j] = -1;

        int ans = (grid1[i][j] == 1);
        ans = ans & dfs(i+1, j, grid1, grid2);
        ans = ans & dfs(i-1, j, grid1, grid2);
        ans = ans & dfs(i, j+1, grid1, grid2);
        ans = ans & dfs(i, j-1, grid1, grid2);

        return ans;


    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();

        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j] == 1 && dfs(i, j, grid1, grid2)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


/*
    BFS Solution 
    tc: o(n*m)
    sc: o(n*m), queue 
*/
class Solution {
public:
    int n, m;
    bool bfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        
        bool result = true;
        queue<pair<int,int>> q;
        q.push({i, j});

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            if(grid1[x][y] != 1){
                result = false;
            }

            int delRow[4] = {0, 1, 0, -1};
            int delCol[4] = {-1, 0, 1, 0};
             for(int i=0; i<4; i++){
                int nr = x + delRow[i];
                int nc = y + delCol[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid2[nr][nc] == 1){
                    grid2[nr][nc] = -1;
                    q.push({nr, nc});
                }
            }
        }
        return result;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();

        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j] == 1 && bfs(i, j, grid1, grid2)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};