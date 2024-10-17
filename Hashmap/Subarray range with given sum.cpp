/*
gfg question 

*/
/*
brute force

tc: o(n^3)
sc: o(1)
*/
class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        int n = arr.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int sum = 0;
                for(int k=i; k<=j; k++){
                    sum += arr[k];
                }
                if(sum == tar) ans++;
            }
        }
        return ans;
    }
};

/*

tc: o(n^2)
sc: o(1)
*/
class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        int n = arr.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                // cout << arr[j]<< ",";
                sum += arr[j];
                if(sum == tar) ans++;
            }
            // cout<<endl;
            
        }
        return ans;
    }
};


/*

tc: o(n)
sc: o(n)
*/

class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        int n = arr.size();
        unordered_map<int,int> mp;
        int sum = 0, ans = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum == tar){
                ans++;
            }
            else if(mp.find(sum-tar) != mp.end()){
                ans += mp[sum-tar];
            }
            mp[sum]++;
        }
        return ans;
    }
};
/* ----------------------------------or--------------------------------------------*/
class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        int n = arr.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0, ans = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            int remove = sum - tar;
            ans += mp[remove];
            mp[sum]++;
        }
        return ans;
    }
};
