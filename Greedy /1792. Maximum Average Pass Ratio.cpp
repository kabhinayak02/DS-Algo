/*
using greedy 

tc: o(n.n)
sc: o(n)
*/
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        vector<double> PR(n);

        for(int i=0; i<n; i++){
            double ratio = (double)classes[i][0]/classes[i][1];
            PR[i] = ratio;
        }

        while(extraStudents--){
            vector<double> updatedPR(n); // after updating all the classes, just to check which one has the maximum change 
            for(int i=0; i<n; i++){
                double newRatio = (double)(classes[i][0]+1)/(classes[i][1]+1);
                updatedPR[i] = newRatio;
            }

            // check for maximum change (delta)
            int bestClassIdx = 0; 
            double bestDelta = 0.0;

            for(int i=0; i<n; i++){
                double delta = updatedPR[i] - PR[i];
                if(delta > bestDelta){
                    bestDelta = delta;
                    bestClassIdx = i;
                }
            }

            PR[bestClassIdx] = updatedPR[bestClassIdx];
            classes[bestClassIdx][0]++;
            classes[bestClassIdx][1]++;
        }
        
        double result = 0.0;
        for(int i=0; i<n; i++){
            result += PR[i];
        }
        return result/n;
    }
};

/*
using heap 

optimised the searching maxi delta with o(1) instead of o(n) as in the above solution 

tc: o(extraStudentslogn)
sc: o(n)
*/
class Solution {
public:
    #define P pair<double,int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<P> pq; // {max Delta, idx}
        for(int i=0; i<n; i++){
            double curr_PR = (double)classes[i][0]/classes[i][1];
            double new_PR = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = new_PR - curr_PR;
            pq.push({delta, i});
        }
        while(extraStudents--){
            P curr = pq.top();
            pq.pop();

            double delta = curr.first;
            int idx = curr.second;

            classes[idx][0]++;
            classes[idx][1]++;

            double curr_PR = (double)classes[idx][0]/classes[idx][1];
            double new_PR = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            double newDelta = new_PR - curr_PR;
            pq.push({newDelta, idx});

        }

        double ans = 0.0;
        for(int i=0; i<n; i++){
            ans += (double)classes[i][0]/classes[i][1];
        }
        return ans/n;
    }
};