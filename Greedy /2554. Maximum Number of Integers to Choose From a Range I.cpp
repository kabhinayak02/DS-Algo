/*
Approach 1: Array Traverse, Greedy 

start from the 1 add them in sum and skip the banned number and check if sum should not exceeds the maxSum

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int sum = 0;
        int count = 0;
        sort(banned.begin(), banned.end());
        unordered_set<int> bannedSet(banned.begin(), banned.end()); 
        
        for (int i = 1; i <= n; i++) {
            if(bannedSet.count(i)){
                continue;
            }  
            sum += i;
            if (sum > maxSum){
                break;
            }
            count++;
            
        }
        return count;
    }
};