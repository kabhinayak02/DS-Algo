/*
using permutations method

Worst Case: O(n * (n+1)!), if iterates through all (n+1)! permutations.
Best Case: O(n), already matches the pattern

sc: o(n)
*/


class Solution {
    public:
        bool matchPattern(string& num, string& pattern){
            for(int i=0; i<pattern.size(); i++){
                if((pattern[i] == 'I' && num[i] > num[i+1]) || (pattern[i] == 'D' && num[i] < num[i+1])){
                    return false;
                }
            }
            return true;
        }
        string smallestNumber(string pattern) {
            int n = pattern.size();
            string num = "";
            for(int i=1; i<=n+1; i++){
                num.push_back(i + '0');
            }
    
            while(!matchPattern(num, pattern)){
                next_permutation(num.begin(), num.end());
            }
    
            return num;
        }
    };

/*
using stack 

tc: o(2*n)
sc: o(n+1)
*/
class Solution {
    public:
        string smallestNumber(string pattern) {
            int n = pattern.size();
    
            string num = "";
            int counter = 1;
            stack<char> st;
    
            for(int i=0; i<=n; i++){
                st.push(counter+'0');
    
                if(pattern[i] == 'I' || i == n){
                    while(!st.empty()){
                        num += st.top();
                        st.pop();
                    }
                }
                counter++;
            }
            return num;
        }
    };