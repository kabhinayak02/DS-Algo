/*
[TLE] Brute force

tc: o(n.m)
sc: o(m)
*/

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();
        vector<int> ans;
        for(int i=0; i<m; i++){
            int diff = INT_MAX;
            int mayAns = 0;
            for(int j=0; j<n; j++){
                if(queries[i] >= items[j][0]){
                    mayAns = max(mayAns, items[j][1]);
                }
            }
            ans.push_back(mayAns);
        }
        return ans;
    }
};

/*
[AC]using binary search

tc: o(nlogn + n + mlogn)
sc: o(m)
*/
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();

        sort(items.begin(), items.end()); // o(nlogn)

        int maxBeauty = 0;
        for(int i=0; i<n; i++){ // o(n)
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }

        vector<int> ans;
        
        for(int k=0; k<m; k++){ // o(m)
            int i = 0, j = n-1;
            int mayAns = 0;
            while(i <= j){ // o(logn)
                int mid = (i+j)/2;
                if(items[mid][0] <= queries[k]){
                    i = mid+1;
                    mayAns = max(mayAns, items[mid][1]);
                }
                else{
                    j = mid-1; 
                }
            }
            ans.push_back(mayAns);
        }
        return ans;
    }
};