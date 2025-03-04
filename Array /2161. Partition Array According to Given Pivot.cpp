/*
using 2 loop 
tc: o(n)
sc: o(n), storing the ans
*/
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(), cnt = 0;
        vector<int> result;
        for(int i=0; i<n; i++){
            if(nums[i] < pivot){
                result.push_back(nums[i]);
            }
            if(nums[i] == pivot){
                cnt++;
            }
        }
        while(cnt--){
            result.push_back(pivot);
        }
        for(int i=0; i<n; i++){
            if(nums[i] > pivot){
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};

/*
using single loop 
tc: o(n)
sc: o(n), storing the ans
*/
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n, pivot);

        int i = 0, j = n-1;
        int left = 0, right = n-1;
        while(i < n && j >= 0){
            if(nums[i] < pivot){
                result[left] = nums[i];
                left++;
            }
            if(nums[j] > pivot){
                result[right] = nums[j];
                right--;
            }
            i++;
            j--;
        }
        return result;

    }
};