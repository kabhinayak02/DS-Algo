/*
using map

tc: o(nlogn)
sc: o(n)
*/
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;
        for(auto trip: trips){
            mp[trip[1]]+=trip[0];
            mp[trip[2]]-=trip[0];
        }
        int ans = 0;
        for(auto it: mp){
            ans += it.second;
            if(ans > capacity) return false;
        }
        return true;
    }
};

/*
using vector with sorting 

tc: o(nlogn)
sc: o(n)
*/
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> mp;
        for(auto trip: trips){
            mp.push_back({trip[1], trip[0]});
            mp.push_back({trip[2], -trip[0]});
        }

        sort(mp.begin(), mp.end());
        
        int ans = 0;
        for(auto it: mp){
            ans += it.second;
            if(ans > capacity) return false;
        }
        return true;
    }
};