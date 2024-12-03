/*
Naive Approach: Every time mismatch happens start the pattern string again. 

tc: o(n.m), n -> length of txt, m -> length of pat
sc: o(m)
*/




/*
KMP - Algo

Step 1: pre - compute LPS (Longest prifix and suffix) vector array.
The LPS array (or vector) stores the length of the longest proper prefix which is 
also a suffix for the substring of the pattern from index 0 to i.

Proper Prefix: A prefix that is not the entire string.
Proper Suffix: A suffix that is not the entire string.

Purpose of LPS:
When a mismatch occurs during pattern matching, the LPS array tells us the next position to start 
comparing in the pattern, rather than starting from the beginning (index 0), as in the naive approach.

Key Insight:
Using the LPS array, we can "skip" unnecessary comparisons by jumping back to the previous 
position in the pattern where a match could possibly continue.

Step 2: Traverse the txt string and check for the pattern with computed LPS array 
While traversing the txt string if mismatch happens at (txt, pat) -> (i, j) go back to the LPS[j-1] and check again for match 
if its still not matching again do the same step, if j == 0, just move the i forward as no sub-string is matching.

with using KMP Approach we improve the time complexity from o(n.m) to o(n+m)

tc: o(n+m)
sc: o(m)
*/
class Solution {
  public:
    void computeLPS(string &pat, vector<int> &LPS, int M){
        int len = 0;
        LPS[0] = 0; // always LPS[0] == 0, means no prifix and no suffix 
        int i = 1; // So, LPS of 0th index is 0, we start with index 1
        while(i < M){
            if(pat[i] == pat[len]){
                len++;
                LPS[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = LPS[len-1];
                }
                else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
    vector<int> search(string& pat, string& txt) {
        int N = txt.length();
        int M = pat.length();
        
        vector<int> ans;
        
        vector<int> LPS(M, 0);
        computeLPS(pat, LPS, M);
        
        int i = 0;
        int j = 0;
        while(i < N){
            if(txt[i] == pat[j]){
                i++;
                j++;
            }
            if(j == M){ // got one answer (i..e index)
                ans.push_back(i-M);
                j = LPS[j-1];
            }
            else if(txt[i] != pat[j]){
                if(j != 0){
                    j = LPS[j-1]; // move to previous same pattern index 
                }
                else{ // If no previous same pattern index, then just move i.
                    i++;
                }
            }
        }
        return ans;
    }
};