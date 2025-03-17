/*
using binary search 

tc: o(n*log(maxR*cars*cars)
sc: o(1)
*/
class Solution {
public:
    typedef long long ll;
    bool isPossible(vector<int>& ranks, int cars, ll mid){
        ll carFixed = 0;
        for(int i=0; i<ranks.size(); i++){
            carFixed += sqrt(mid/ranks[i]);
        }
        return carFixed >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        ll ans = -1;
        int maxR = *max_element(ranks.begin(), ranks.end()); // machinic who has most rank (will take more time) 
        ll l = 1;                           // minimum time 
        ll r = 1LL * maxR * cars * cars;    // maximum time (machinic who took most time )

        // Binary search 
        while(l <= r){
            ll mid = l + (r-l)/2; // mid time 
            if(isPossible(ranks, cars, mid)){ // check if time (mid) can vaild answer to fix all cars 
                r = mid - 1; // if yes, move right to right for miniumim time (mid) need
                ans = mid; // store as of now best time (minimum)
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};