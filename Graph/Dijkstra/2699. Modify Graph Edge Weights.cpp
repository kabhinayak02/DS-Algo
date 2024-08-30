/*
    Dijkstra Algo

    tc: o(E * (E * logV))
    sc: o(E + V)
*/
class Solution {
public:
    typedef long long ll;
    const int LARGE_VALUE = 2e9;

    ll Dijkstra(vector<vector<int>>& edges, int n, int source, int destination){

        unordered_map<ll, vector<pair<ll,ll>>> adj;
        
        // Form a graph except -1 edges
        for(vector<int>& edge: edges){
            if(edge[2] != -1){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        
        vector<ll> dist(n, INT_MAX);
        vector<bool> visited(n, false);
        
        pq.push({0, source});
        dist[source] = 0;

        while(!pq.empty()){
            int currNode = pq.top().second;
            int currDist = pq.top().first;
            pq.pop();

            if(visited[currNode] == true) continue;

            visited[currNode] = true;

            for(auto& [ngbr, wt]: adj[currNode]){
                if(dist[ngbr] > currDist + wt){
                    dist[ngbr] = currDist + wt;
                    pq.push({dist[ngbr], ngbr});
                }
            }
        }
        
        return dist[destination];
        
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll currShortestDist = Dijkstra(edges, n, source, destination);

        // Case 1: when current shortest dist is less than the target, so Dijkstra always choose the same path 
        if(currShortestDist < target){
            return {};
        }

        bool matchedTarget = (currShortestDist == target);

        // Case 2: current shortest dist matched with the target, so we just repalce all the -1 to maximum.
        // NOTE: You can ignore this code section as it is already covered in the next case
        if(matchedTarget == true){
            for(vector<int>& edge: edges){
                if(edge[2] == -1){
                    edge[2] = LARGE_VALUE;
                }
            }

            return edges;
        }

        // Case 3: current shortest dist is larger than the target, So now we choose all the -1 path and 
        // convert it to 1 if matched target is false, add the diff of shortest dist and target to any edges.
        for(vector<int>& edge: edges){
            if(edge[2] == -1){

                edge[2] = (matchedTarget == true) ? LARGE_VALUE: 1;

                if(matchedTarget != true){
                    ll newShortestDist = Dijkstra(edges, n, source, destination);

                    if(newShortestDist <= target){
                        matchedTarget = true;
                        edge[2] += (target - newShortestDist);
                    }
                }
            }
        }

        if(matchedTarget == false){
            return {};
        }
        return edges;
    }
};