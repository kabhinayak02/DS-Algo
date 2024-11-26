/*
uisng indegree vector and the index with 0 indegree is winner if there is no other indegree with 0.

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];

            indegree[v]++;
        }

        int countZero = 0, canAns = -1;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                countZero++;
                canAns = i;
            }
        }
        return countZero > 1 ? -1 : canAns;
    }
};