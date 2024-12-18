/*
using 2 loop, brute force approach

tc: o(n.n)
sc: o(n)
*/
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            int j;
            for(j=i+1; j<n; j++){
                if(prices[j] <= prices[i]){
                    ans.push_back(prices[i] - prices[j]);
                    break;
                }
            }
            if(j == n){
                ans.push_back(prices[i]);
            }
        }
        return ans;
    }
};

/*
using monotonic stack 

tc: o(2n)
sc: o(n)
*/
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(prices.begin(), prices.end());
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && prices[i] <= prices[st.top()]){
                ans[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};