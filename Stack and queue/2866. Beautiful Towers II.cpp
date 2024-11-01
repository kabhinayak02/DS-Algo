/*
using stack 

create a prefix with next left smallest element and suffix next right smallest element

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    typedef long long ll;
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<ll> prefix(n), suffix(n);
        stack<int> st;

        st.push(0);
        prefix[0] = maxHeights[0];

        for(int i=0; i<n; i++){
            while(!st.empty() && maxHeights[st.top()] > maxHeights[i]){
                st.pop();
            }

            // If stack become empty means no left smallest element found or curr element is the smallest one 
            // calculate the length from [0, i] with curr element maxHeight 
            if(st.empty()){
                prefix[i] = 1ll * (i+1) * maxHeights[i];
                st.push(i);
                continue;
            }

            // If next left smallest found calculate the length from it'th position and height with curr element
            int it = st.top();
            prefix[i] = prefix[it] + (ll)(i-it) * maxHeights[i];
            st.push(i);
        }

        // empty the stack 
        while(!st.empty()) st.pop();

        st.push(n-1);
        suffix[n-1] = maxHeights[n-1];

        for(int i=n-2; i>=0; i--){
            while(!st.empty() && maxHeights[st.top()] > maxHeights[i]) {
                st.pop();
            }

            if(st.empty()){
                suffix[i] = 1ll*(n-i) * maxHeights[i];
                st.push(i);
                continue;
            }

            int it = st.top();
            suffix[i] = suffix[it] + (ll)(it-i) * maxHeights[i];
            st.push(i);
        }

        // Now, calculate the final answer
        ll maxSum = 0;
        for(int i=0; i<n; i++){
            maxSum = max(maxSum, prefix[i] + suffix[i] - maxHeights[i]);
        }

        return maxSum;
    }
};