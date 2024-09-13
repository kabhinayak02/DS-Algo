#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
    
    vector<int> dis(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0,S});
    dis[S] = 0;
    
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        
        for(auto it: adj[u]){
            int v = it[0];
            int w = it[1];
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
    return dis;
}