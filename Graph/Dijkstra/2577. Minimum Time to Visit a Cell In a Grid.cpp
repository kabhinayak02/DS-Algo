/*
Using Dijkstra 

tc: o(n.mlog(n.m))
sc: o(n.m)
*/
class Solution {
public:
    #define P pair<int,pair<int,int>> 
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][1] > 1 && grid[1][0] > 1){
            return -1;
        }

        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        ans[0][0] = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        priority_queue<P, vector<P>, greater<P>> pq; // {time, {row, col}}
        pq.push({0, {0, 0}}); // push starting row and col (0, 0)

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int time = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            if(row == m-1 && col == n-1){
                return ans[row][col];
            }

            if(visited[row][col] == true){
                continue;
            }
            visited[row][col] = true;

            for(auto &dir: directions){
                int nrow = row + dir[0];
                int ncol = col + dir[1];

                if(nrow < 0 || nrow >= m || ncol < 0 || ncol >= n){
                    continue;
                }

                if(grid[nrow][ncol] <= time+1){
                    pq.push({time+1, {nrow, ncol}});
                    ans[nrow][ncol] = time+1;
                }
                else if((grid[nrow][ncol] - time) % 2 == 0){
                    pq.push({grid[nrow][ncol]+1, {nrow, ncol}});
                    ans[nrow][ncol] = grid[nrow][ncol]+1;
                }
                else{
                    pq.push({grid[nrow][ncol], {nrow, ncol}});
                    ans[nrow][ncol] = grid[nrow][ncol];
                }
            }

        }
        return ans[m-1][n-1];
    }
};


/*
Using Dijkstra (without storing ans vector)

tc: o(n.mlog(n.m))
sc: o(n.m)

*/
class Solution {
public:
    #define P pair<int,pair<int,int>> 
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][1] > 1 && grid[1][0] > 1){
            return -1;
        }

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        priority_queue<P, vector<P>, greater<P>> pq; // {time, {row, col}}
        pq.push({0, {0, 0}}); // push starting row and col (0, 0)

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int time = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            if(row == m-1 && col == n-1){
                return time;
            }

            if(visited[row][col] == true){
                continue;
            }
            visited[row][col] = true;

            for(auto &dir: directions){
                int nrow = row + dir[0];
                int ncol = col + dir[1];

                if(nrow < 0 || nrow >= m || ncol < 0 || ncol >= n){
                    continue;
                }

                if(grid[nrow][ncol] <= time+1){
                    pq.push({time+1, {nrow, ncol}});
                }
                else if((grid[nrow][ncol] - time) % 2 == 0){ // even
                    pq.push({grid[nrow][ncol]+1, {nrow, ncol}});
                }
                else{ // odd 
                    pq.push({grid[nrow][ncol], {nrow, ncol}});
                }
            }

        }
        return -1;
    }
};