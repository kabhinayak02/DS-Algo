/*

issue in this code is we are manipulating the original array which is not good practice.

tc: o(n.32)
sc: o(1)
*/
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for(int i=0; i<32; i++){
            int cntOne = 0;
            for(int j=0; j<candidates.size(); j++){
                if(candidates[j] & 1 != 0){
                    cntOne++;
                }
                candidates[j] = candidates[j] >> 1;
            }
            ans = max(ans, cntOne);
            
        }
        return ans;
    }
};

/*

here we left shifting the 1 at every next bits which will not affect the original array 

tc: o(n.32)
sc: o(1)
*/

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for(int i=0; i<32; i++){
            int cntOne = 0;
            for(int j=0; j<candidates.size(); j++){
                if(candidates[j] & (1 << i)){
                    cntOne++;
                }
            }
            ans = max(ans, cntOne);
            
        }
        return ans;
    }
};