/*
tc: o(n)
sc: o(n)

traverse from y axis and take the count of x points 
create a map [y-axis, count] -> how many points are in y-axis 
count-c-2 -> how many pair you can make 

current horizontal lines can make trapez with prev horizontal lines 

[NOTE] This iis only valid for if you have horizontal lines 
see 3625 for non-horizontal

*/
class Solution {
public:
    int mod = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) { // {x, y}
        int n = points.size();
        map<int,int> mp;
        for(int i=0; i<n; i++){
            int y = points[i][1];
            mp[y]++;
        }

        long long ans = 0;
        long long prevHorizontalLines = 0;
        for(auto &it: mp){
            int count = it.second;

            long long horizontalLines = (long long)count*(count-1)/2;

            ans += horizontalLines * prevHorizontalLines;
            prevHorizontalLines += horizontalLines;
        }

        return ans%mod;


    }
};