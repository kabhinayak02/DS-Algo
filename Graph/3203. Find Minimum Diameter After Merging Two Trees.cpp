/*
using level order traversal and BFS 

tc: o(v1+e1+v2+e2)
sc: o(v1+e1+v2+e2)
*/
class Solution {
public:
    pair<int,int> BFS(unordered_map<int, vector<int>>& adj, int source){

        queue<int> q;
        q.push(source);

        unordered_map<int, bool> visited;
        visited[source] = true;

        int distance = 0;
        int farthestNode = source;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int node = q.front();
                q.pop();

                farthestNode = node;

                for(auto &ngbr: adj[node]){
                    if(visited[ngbr] == false){
                        visited[ngbr] = true;
                        q.push(ngbr);
                    }
                }
            }
            if(!q.empty()){
                distance++;
            }
            
        }

        return {farthestNode, distance};
    }
    int findDiameter(unordered_map<int, vector<int>>& adj){
        // step 1: find the farthest distance node from source 0 
        auto [farthestNode, dist] = BFS(adj, 0);

        // step 2: find the 2nd farthest distance node from the 1st farthest node.
        auto [lastFarthestNode, diameter] = BFS(adj, farthestNode);

        return diameter;
    }
    unordered_map<int, vector<int>> buildGraph(vector<vector<int>>& edges){
        unordered_map<int, vector<int>> adj;
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = buildGraph(edges1);
        unordered_map<int, vector<int>> adj2 = buildGraph(edges2);

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);
        int d3 = (d1+1)/2 + (d2+1)/2 + 1;

        int ans = max({d1, d2, d3});
        return ans;
    }
};