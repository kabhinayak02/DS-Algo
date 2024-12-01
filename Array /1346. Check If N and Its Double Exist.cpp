/*
Brute force 

tc: o(n.n)
sc: o(1)
*/
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j && arr[i] == 2 * arr[j]){
                    return true;
                }
            }
        }
        return false;
    }
};

/*
Optimised Appraoch, using set or hash map

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st;

        for(int i=0; i<n; i++){
            if(st.find(arr[i]*2) != st.end()){
                return true;
            }
            else if(arr[i]%2 == 0 && st.find(arr[i]/2) != st.end()){
                return true;
            }
            st.insert(arr[i]);
        }
        return false;
    }
};