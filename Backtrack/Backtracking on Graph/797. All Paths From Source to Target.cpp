
// tc: o(2^n.n), n -> no. of vertices
// sc: o(2^n.n)
class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int> &temp, int src, int n, vector<vector<int>> &graph){
        if(src == n-1) {
            ans.push_back(temp);
            return;
        }

        for(int x: graph[src]){
            temp.push_back(x);
            dfs(ans, temp, x, n, graph);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(0);

        dfs(ans, temp, 0, n, graph);

        return ans;
    }
};