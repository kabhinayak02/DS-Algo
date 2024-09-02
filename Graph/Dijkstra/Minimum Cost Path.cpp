/*
GFG Problem: https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1


tc: o((n*m)log(n*m))
sc: o(n*m)
*/

typedef pair<int,int> P;

int minimumCostPath(vector<vector<int>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    
    int dist[n][m];
    
    // Initialize the distance array with infinity
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dist[i][j] = INT_MAX;
        }
    }
    
    // Priority queue to process cells in order of minimum cost
    priority_queue<pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>>> pq;
    
    dist[0][0] = grid[0][0];
    pq.push({dist[0][0], {0, 0}});
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();
        
        if(i == n-1 && j == m-1) break;  // Early exit when reaching the bottom-right corner
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        
        // Traverse all four directions
        for(int k = 0; k < 4; k++) {
            int nr = i + dx[k];
            int nc = j + dy[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                // Update the distance if a shorter path is found
                if(dist[nr][nc] > dist[i][j] + grid[nr][nc]) {
                    dist[nr][nc] = dist[i][j] + grid[nr][nc];
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
    }
    
    return dist[n-1][m-1];
}
