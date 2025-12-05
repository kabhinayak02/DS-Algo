/*

tc: o(n^2)
sc: o(n^2)

tricky part is how to handle parallelograms, as they are also counted in the slope-intercept method.
To handle parallelograms, we can use the property that the diagonals of a parallelogram bisect each other.
So, for each pair of points, we can calculate the midpoint and group the slopes of lines that share the same midpoint.
Then, we can subtract the count of parallelograms from the total count of trapezoids.
*/

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) { 
        int n = points.size();
    
        unordered_map<float, vector<float>> slopeIntercepts; // slope -> [intercepts]
        unordered_map<int, vector<float>> midPointMap; // midPointKey -> [slope]

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                
                int x2 = points[j][0];
                int y2 = points[j][1];

                // slope and intercept 
                int dx = x2-x1;
                int dy = y2-y1;

                float slope, intercept;
                if(x2 == x1){
                    slope = 1e9+7;
                    intercept = x1;
                }
                else{
                    slope = (float)(dy)/(dx);
                    intercept = (float)(y1*dx - x1*dy)/dx;
                } 
                
                int midPointKey = (x1+x2)*10000 + (y1+y2);

                slopeIntercepts[slope].push_back(intercept);
                midPointMap[midPointKey].push_back(slope);
                
            }
        }

        int ans = 0;
        for(auto &it: slopeIntercepts){
            map<float, int> mp; // intercept -> count;
            for(float intercept: it.second){
                mp[intercept]++;
            }
            int prevHorizontalLines = 0;
            for(auto &it: mp){
                int count = it.second;
                ans += count * prevHorizontalLines;
                prevHorizontalLines += count;
            }
        }

        for(auto &it: midPointMap){
            map<float, int> mp;
            for(float slope: it.second){ // slope -> count;
                mp[slope]++;
            }

             int prevHorizontalLines = 0;
            for(auto &it: mp){
                int count = it.second;
                ans -= count * prevHorizontalLines;
                prevHorizontalLines += count;
            }
        }


        return ans;
    }
};