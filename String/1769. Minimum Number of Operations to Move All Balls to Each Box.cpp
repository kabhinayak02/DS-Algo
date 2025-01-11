/*
brute force: using 2 loop [AC]

brute force 
tc: o(n.n)
sc: o(n) for storing ans
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            int step = 0;
            for(int j=0; j<n; j++){
                if(i == j) continue;

                if(boxes[j] == '1') {
                    step += abs(j-i);
                }
            }
            ans.push_back(step);
        }
        return ans;
    }
};

/*
brute force - 2 [AC]

tc: o(n.n)
sc: o(n) for storing ans
*/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            if(boxes[i] == '1'){
                for(int j=0; j<n; j++){
                    ans[j] += abs(j-i); 
                }
            }
        }
        return ans;
    }
};

/*
[AC]
tc: o(n+n)
sc: o(n) for storing ans
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);

        int cumValueSum = 0;
        int cumValue = 0;

        for(int i=0; i<n; i++){
            ans[i] = cumValueSum;
            cumValue += boxes[i] == '1' ? 1 : 0;
            cumValueSum += cumValue;
        }

        cumValueSum = 0;
        cumValue = 0;

        for(int i=n-1; i>=0; i--){
            ans[i] += cumValueSum;
            cumValue += boxes[i] == '1' ? 1 : 0;
            cumValueSum += cumValue;
        }

        return ans;
    }
};