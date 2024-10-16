
/*
Use simple BFS to find the shortest dist

*/
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> distArray(N, 1e9);
        
        queue<pair<int,int>> q;
        q.push({src, 0});
        distArray[src] = 0;
        
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            for(auto ngbr: adj[node]){
                if(distArray[ngbr] == 1e9){
                    distArray[ngbr] = dist + 1;
                    q.push({ngbr, dist+1});
                }
                else if(distArray[ngbr] > dist + 1){
                    distArray[ngbr] = dist + 1;
                }
            }
        }
        
        for(int i=0; i<N; i++){
            if(distArray[i] == 1e9){
                distArray[i] = -1;
            }
        }
        return distArray;
    }
};