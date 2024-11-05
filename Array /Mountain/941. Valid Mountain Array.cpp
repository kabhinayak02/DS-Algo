/*
using flag -> when slop will change, in mountain only one time (at peak) slope will change 
check -> if elements in the array is monotonically increasing only or decreasing only(no peak) 

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();

        int flag = 0, check = 0;
        for(int i=1; i<n; i++){
            if(arr[i-1] - arr[i] < 0){
                check++;
                if(flag == 1) return false;
            }
            else if(arr[i-1] - arr[i] > 0){
                check--;
                flag = 1;
            }
            else return false;
        }
        // cout << check << endl;
        if(abs(check) == n-1) return false;
        // if(flag == 0) return false;
        return flag == 1;
    }
};

/*
More intuitive and more logical 

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;

        int i = 0;

        // Walk up the mountain
        while (i + 1 < n && arr[i] < arr[i + 1]) {
            i++;
        }

        // Check if peak is not at the beginning or end
        if (i == 0 || i == n - 1) {
            return false;
        }

        // Walk down the mountain
        while (i + 1 < n && arr[i] > arr[i + 1]) {
            i++;
        }

        // If we've reached the end, it's a valid mountain array
        return i == n - 1;
    }
};