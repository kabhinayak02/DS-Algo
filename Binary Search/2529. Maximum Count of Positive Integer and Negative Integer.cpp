/*
using counting 

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int neg = 0, pos = 0;
        for(int i=0; i<n; i++){
            if(nums[i] < 0){
                neg++;
            }
            else if(nums[i] > 0){
                pos++;
            }
        }
        return max(neg, pos);
    }
};

/*
using stl 

lower_bound uses binary search internally 

tc: o(logn)
sc: o(1)
*/
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int pos = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();

        return max(n - pos, neg);
    }
};


/*
using binary search 

tc: o(logn)
sc: o(1)
*/
class Solution {
public:
    int binarySearch(vector<int>& nums, int target){
        int left = 0, right = nums.size()-1, result = nums.size();

        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                result = mid;
                right = mid - 1;
            }
        }
        return result;
    }
    int maximumCount(vector<int>& nums) {
        int neg = binarySearch(nums, 0);
        int pos = nums.size() - binarySearch(nums, 1);
        return max(pos, neg);
    }
};