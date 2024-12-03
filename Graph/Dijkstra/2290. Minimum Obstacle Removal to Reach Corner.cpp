/*
using dijkstra algorithm

treat obstacle as a path weight or path cost, so whenever we pass the path with obstacle we have to pay the 
cost of it i.e 1. Now implement the min heap with wt. 

tc: o(E.log(V)) -> o((n.m)log(m.n))
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
                int wt = grid[x][y] == 1 ? 1 : 0; // If obstacle wt = 1 else 0
                if(d + wt < ans[x][y]){
                    ans[x][y] = d + wt;
                    pq.push({d+wt, {x, y}});
                }
            }
        }
        return ans[m-1][n-1];
    }
};