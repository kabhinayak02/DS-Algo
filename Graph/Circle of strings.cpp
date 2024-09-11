/*
GFG Link: https://practice.geeksforgeeks.org/problems/circle-of-strings/1

*/

class Solution {
  public:
     void dfs(int node,vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        
        for(auto &it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int isCircle(vector<string> &arr) {
        // Step 1: Create a adjacency list, indegree and outdegree 
        vector<int>adj[26];
        vector<int>in(26,0),out(26,0);

        for(auto it:arr){
            int u=it[0]-'a'; // first element 
            int v=it[it.size()-1]-'a'; // last element 
            adj[u].push_back(v); // edge 
            in[v]++; // in degree
            out[u]++; // out degree
        }

        // Step 2: Check if the indegree and outdegree are not equal
        for(int i=0;i<26;i++){ 
            if(in[i]!=out[i]) return 0; 
        }
        
        // Step 3: Use dfs: Check for strongly connected component
        vector<int>vis(26,0);
        dfs(arr[0][0]-'a',adj,vis);
        
        // Step 4: If any node whose indeg or outdeg is not zero and not visited, then circle is impossible
        for(int i=0;i<26;i++){
            if(!vis[i] and in[i]) return 0;
        }    
        
        return 1;
    }
};