/*
using Euler Path (Hierholzer's Algorithm)

find the indegree and outdegree of each pair elements and use dfs to find the path, starting node only have
outdegree, no indegree and similarly end node have indegree with no outdegree.

tc: o(v+e)
sc: o(n)
*/
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        unordered_map<int, vector<int>> adj;
        unordered_map<int,int> indegree, outdegree;

        for(auto &edge: pairs){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }

        int startNode = pairs[0][0];
        for(auto &it: adj){
            int node = it.first;
            if(outdegree[node] - indegree[node] == 1){
                startNode = node;
                break;
            }
        }

        vector<int> path; //Eulers Path 
        stack<int> st;
        st.push(startNode);

        while(!st.empty()){
            int curr = st.top();
            if(!adj[curr].empty()){
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            }
            else{
                path.push_back(curr);
                st.pop();
            }
        }
        
        reverse(path.begin(), path.end());
        vector<vector<int>> ans;
        for(int i=0; i<path.size()-1; i++){
            ans.push_back({path[i], path[i+1]});
        }
        return ans;
    }
};