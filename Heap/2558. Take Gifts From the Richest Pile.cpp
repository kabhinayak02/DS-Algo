/*
using max heap 

tc: o(nlogn)
sc: o(n)
*/
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        long long ans = 0;
        while(k--){
            int gift = pq.top();
            pq.pop();
            pq.push(sqrt(gift));
        }
        while(!pq.empty()){
            int gift = pq.top();
            pq.pop();
            ans += gift;
        }
        return ans;
    }
};