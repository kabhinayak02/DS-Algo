/*
brute force 

tc: o(n.n)
sc: o(1)
*/
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int area = (j-i) * (min(arr[i], arr[j]));
                ans = max(ans, area);
            }
        }
        return ans;
    }
};


/*
optimal 

tc: o(n)
sc: o(1)
*/
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        int ans = 0;
        int i = 0, j = n-1;
        while(i < j){
            int area = (j-i) * (min(arr[i], arr[j]));
            ans = max(ans, area);
            
            if(arr[i] < arr[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};