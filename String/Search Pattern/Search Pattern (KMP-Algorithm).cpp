/*
Naive Approach 

tc: o(n.m), n -> length of txt, m -> length of pat
sc: o(m)
*/




/*
KMP - Algo

Step 1: Compute LPS (Longest prifix and suffix) -> pre-computing 


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

