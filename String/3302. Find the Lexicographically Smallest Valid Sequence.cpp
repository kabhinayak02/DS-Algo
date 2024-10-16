/*
tc: o(n)
sc: o(n)

*/
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int i = n-1; // word1
        int j = m-1; // word2
        vector<int> maxSuffix(n, 0);
        while(i >= 0 && j >= 0){
            if(word1[i] == word2[j]){
                maxSuffix[i] = (m-j);
                i--;
                j--;   
            }
            else{
                i--;
            }
        }

        for(int i=n-2; i>=0; i--){
            maxSuffix[i] = max(maxSuffix[i], maxSuffix[i+1]);
            
        }
        vector<int> ans;
        i = 0, j = 0;
        int check = 0;
        while(i < n && j < m){
            // cout << word1[i] << " " << word2[j] << endl;
            if(word1[i] == word2[j]){
                ans.push_back(i);
                i++;
                j++;
            }
            // else{
            //     if(i+1 < n && check == 0 && maxSuffix[i+1] >= (m-j-1)){
            //         ans.push_back(i);
            //         check = 1;
            //         i++;
            //         j++;
            //     }
            //     else{
            //         i++;
            //     }
            // }
            // or 
            else if(i+1 < n && check == 0 && maxSuffix[i+1] >= (m-j-1)){
                check = 1;
                ans.push_back(i);
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(ans.size() == m) return ans;
        return {};
    }
};