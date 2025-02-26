/*

tc: o(n)
sc: o(n)
using extra space o(n) 
*/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9+7;
        int n = arr.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = arr[0];

        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + arr[i];
        }

        int count = 0;
        int even = 1;
        int odd = 0;

        for(int i=0; i<n; i++){
            if(prefixSum[i] % 2 == 0) { // even sum
                count = (count + odd) % mod;
                even++;
            }
            else{ // odd sum
                count = (count + even) % mod;
                odd++;
            }
        }
        return count;
    }
};


/*

tc: o(n)
sc: o(1)
without extra space 
*/
class Solution {
    public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9+7;
        int n = arr.size();
        int sum = 0, cnt = 0;
        int even = 1, odd = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum % 2 == 0){ // even sum
                cnt = (cnt + odd) % mod;
                even++;
            }
            else{
                cnt = (cnt + even) % mod;
                odd++;
            }
        }
        return cnt;
    }
};

