/*
gfg link: https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
*/

/*
brute force [TLE]

tc: o(n.n.n)
sc: o(1)
*/

3 loop solution 


/*
better solution [TLE]

tc: o(n.n)
sc: o(1)
*/

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        int count = 0;
        for(int i=0; i<n; i++){
            int a = arr[i];
            if(a == k) count++;
            for(int j=i+1; j<n; j++){
                a ^= arr[j];
                if(a == k) count++;
            }
        }
        
        return count;
    }
};

/*
optimal solution (best)

tc: o(n)
sc: o(n)
*/
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int count = 0;
        int currXor = 0;
        for(int i=0; i<n; i++){
            currXor ^= arr[i];
            
            if(mp.find(currXor^k) != mp.end()){
                count += mp[currXor^k];
            }
            
            mp[currXor]++;
        }
        return count;
    }
};