/*
using dijkstra algorithm

tc: o(E.log(V)) -> o(n.mlog(m.n))
sc: o(m.n)
*/

class Solution {
public:
    #define P pair<int,pair<int,int>> 
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int minimumObstacles(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m, vector<int> (n, INT_MAX));
        ans[0][0] = 0; // starting cell always be zero 

        priority_queue<P, vector<P>, greater<P>> pq; // {wt, {i, j}}
        pq.push({0, {0, 0}}); // push starting cell

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int d = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            for(auto &dir: directions){
                int x = i + dir[0];
                int y = j + dir[1];

                if(x < 0 || x >= m || y < 0 || y >= n){
                    continue;
                }
                int wt = grid[x][y] == 1 ? 1 : 0;
                if(d + wt < ans[x][y]){
                    ans[x][y] = d + wt;
                    pq.push({d+wt, {x, y}});
                }
            }
        }
        return ans[m-1][n-1];
    }
};