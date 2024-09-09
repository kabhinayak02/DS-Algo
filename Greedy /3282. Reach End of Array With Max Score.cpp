/*
DP solution can give TLE, so need to think greedy approach. we going to choose next number which is greater 
than current number in array. Then we calculate the score of that number and add it to the sum. 
Other condition is for to jump to the last element irrespective of number.

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    typedef long long ll;
    long long findMaximumScore(vector<int>& nums) {
        ll n = nums.size();
        ll sum = 0;
        ll i = 0;
        for(ll j=0; j<n; j++){
            if(nums[j] > nums[i]){
                ll score = (j-i) * nums[i];
                sum += score;
                i = j;
            }
            else if(j == n-1){
                ll score = (j-i) * nums[i];
                sum += score;
            }
        }
        return sum;
    }
};