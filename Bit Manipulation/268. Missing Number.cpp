/*
Brute force: using Array 

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1, 0);
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }

        for(int i=0; i<n+1; i++){
            if(freq[i] == 0) return i;
        }
        return -1;
    }
};

/*
using Maths

- Sum of n natural numbers = n*(n+1)/2
- Total sum of the array = sum(nums)
- Missing number = total - sum(nums)
- Missing number = n*(n+1)/2 - sum(nums)

tc: o(n)
sc: o(1) 
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n*(n+1)/2;
        for(int i=0; i<n; i++){
            total -= nums[i];
        }
        return total;
    }
}

/*
Using bit manipulation

tc: o(n)
sc: o(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        for(int i=0; i<n; i++){
            ans = ans ^ i ^ nums[i];           
        }
        return ans;
    }
};

/*
Using Sorting and traversing 

tc: o(nlogn + n)
sc: o(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            if(i != nums[i]){
                return i;  // The missing number is 'i'
            }
        }

        // If all numbers from 0 to n-1 are present, the missing number is 'n'
        return n;
    }
};

/*
Using sorting + binary search

tc: o(nlogn + logn)
sc: o(1)
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0, r = n-1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] > mid){
                r = mid - 1; 
            }
            else{
                l = mid + 1;
            }
        }
        return l; 
    }
};