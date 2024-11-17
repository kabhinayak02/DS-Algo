/*
3254. Find the Power of K-Size Subarrays I
3255. Find the Power of K-Size Subarrays II 
*/

/*
Brute force

tc: o(n.k)
sc: o(n)
*/
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        int init = 0;
        for(int i=0; i<n; i++){
            if(i >= k-1){
                int flag = 0;
                for(int j=init+1; j<=i; j++){
                    if(nums[j-1]+1 != nums[j]){
                        ans.push_back(-1);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) ans.push_back(nums[i]);
                init++;
            }
        }
        return ans;
    }
};


/*
optimised solution 

tc: o(n)
sc: o(n)
*/

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        int count = 0;
        if(n == 1 || k == 1) return nums; //edge case
        for(int i=1; i<n; i++){
            if(nums[i-1]+1 == nums[i]){
                count++;
            }
            else {
                count = 0;
            }

            if(i >= k-1 && count >= k-1){
                ans.push_back(nums[i]);
            }
            else if(i >= k-1){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};