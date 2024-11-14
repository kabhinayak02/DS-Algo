/*
using min heap 

push first k element in k, now pop the top element from the min heap and swap or update the array

tc: o(n.k)
sc: o(k)
*/
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>,greater<int>> pq; // min heap
        int n = arr.size();
        
        for(int i=0; i<=k; i++){
            pq.push(arr[i]);
        }
        
        int idx = 0;
        
        for(int i=k+1; i<n; i++){
            arr[idx++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        
        while(!pq.empty()){
            arr[idx++] = pq.top();
            pq.pop();
        }
    }
};