/*
[TLE Solution] Brute Force
- Try all the index as starting point

tc: o(n^2)
sc: o(1)
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for(int i=0; i<n; i++){
            if(gas[i] < cost[i]) continue;

            int j = (i+1)%n;
            // i -> starting point and j -> curr
            int startGasCostToMoveNext = cost[i];
            int startGasUnit = gas[i];
            int currGasUnit = gas[j];

            int currGas = startGasUnit - startGasCostToMoveNext + currGasUnit; 

            while(j != i) {
                if(currGas < cost[j]) break;
                    
                int currCostToMoveNext = cost[j];

                j = (j+1)%n;

                int gasInNextStation = gas[j];

                currGas = currGas - currCostToMoveNext + gasInNextStation;
            }
            if(j == i) return i;
        }
        return -1;
    }
};


/*
[Accepted] Greedy Approach 

We have to travel all the stations so,
observation 1: total gas should be equal to or greater than the costs to travel all the stations, then we get confirm index.
2: If curr gas is less than cost gas. so its not possible to move. So not possible to be starting point. 
3: Try to find the index, where gas is greater than the cost. So atleast possible for starting point.

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);

        if(totalGas < totalCost) return -1;

        int result_index = 0;
        int total = 0;
        for(int i=0; i<n; i++){     
            total += gas[i] - cost[i];
            if(total < 0){
                total = 0;
                result_index = i+1;
            } 
        }
        return result_index;
    }
};