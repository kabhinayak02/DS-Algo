/*
using backtracking
we are filling Lexicographically largest number first.

tc: o(n!)
sc: o(n)
*/
class Solution {
    public:
        bool solve(int i, int n, vector<int>& result, unordered_map<int,bool>& used){
            if(i >= result.size()) return true;
    
            if(result[i] != -1){
                return solve(i+1, n, result, used);
            }
    
            for(int num=n; num>=1; num--){
                if(used[num] == true) continue;
    
                used[num] = true;
                result[i] = num;
    
                if(num == 1){
                    if(solve(i+1, n, result, used) == true){
                        return true;
                    }
                }
                else {
                    int j = i + num;
                    if(j < result.size() && result[j] == -1){
                        result[j] = num;
                        if(solve(i+1, n, result, used) == true){
                            return true;
                        }
                        result[j] = -1;
                    }
                }
    
                used[num] = false;
                result[i] = -1;
            }
    
            return false;
        }
        vector<int> constructDistancedSequence(int n) {
            unordered_map<int, bool> used;
    
            vector<int> result(2*n-1, -1);
            solve(0, n, result, used);
    
            return result;
        }
    };