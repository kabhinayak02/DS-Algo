/*
Brute Force 

tc: o(n*m) n -> no. of queries, m -> avg. length of sub-queries
sc: o(n)
*/
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            int right = queries[i][0];
            int left = queries[i][1];
            int xorAns = 0;
            for(int j=right; j<=left; j++){
                xorAns ^= arr[j];
            }
            ans.push_back(xorAns);
        }
        return ans;
    }
};

/*
Using bit manipulation 

tc: O(n + m), where n is the size of arr and m is the number of queries.
sc: o(n) n -> size of queries
*/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> xorArray;
        int xorTemp = arr[0];
        xorArray.push_back(xorTemp);
        for(int i=1; i<arr.size(); i++){
            xorTemp ^= arr[i];
            xorArray.push_back(xorTemp);
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            int left = queries[i][0];
            int right = queries[i][1];
            int xorAns = (left == 0 ? 0 : xorArray[left-1]) ^ xorArray[right];
            ans.push_back(xorAns);
        }
        return ans;
    }
};