/*
fixed size sliding window

tc: o(n)
sc: o(1)

*/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int i = 0, j = 0;
        int sum = 0, ans = 0;
        while (j < n) {
            sum += arr[j];
            
            if (j - i + 1 == k) { // Process window when its size equals k
                if (sum >= k * threshold) {
                    ans++;
                }
            }
            
            if (j - i + 1 >= k) { // Slide window when it gets too large
                sum -= arr[i];
                i++;
            }
            
            j++;
        }
        return ans;
    }
};

// same complexity but different way 
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int i = 0, j = 0;
        int sum = 0, ans = 0;
        while (j < n) {
            sum += arr[j];
            
            if (j - i + 1 == k) { // When the window size equals k
                if (sum >= k * threshold) { // Avoid division by using k * threshold
                    ans++;
                }
                sum -= arr[i]; // Slide the window
                i++;
            }
            
            j++;
        }
        return ans;
    }
};

