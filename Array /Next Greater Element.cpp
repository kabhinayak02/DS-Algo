/*
[TLE]

tc: o(n.n)
sc: o(n) for storing the answer)
*/
class Solution {
    public:
      vector<int> nextLargerElement(vector<int>& arr) {
          int n = arr.size();
          vector<int> result(n, -1);
          for(int i=0; i<n; i++){
              for(int j=i+1; j<n; j++){
                  if(arr[j] > arr[i]){
                      result[i] = arr[j];
                      break;
                  }
              }
          }
          return result;
  
      }
  };

/*
[AC]

tc: o(n)
sc: o(n) for storing the answer)
*/
class Solution {
public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> st;

        // Iterate from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements smaller than the current element
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            
            // If stack is not empty, the top is the next greater element
            if (!st.empty()) {
                result[i] = st.top();
            }
            
            // Push the current element to the stack
            st.push(arr[i]);
        }

        return result;

    }
};