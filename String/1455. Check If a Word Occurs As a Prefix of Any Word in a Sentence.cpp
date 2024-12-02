/*
Brute force [AC]

tc: o(n.m)
sc: o(m)
*/
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        string checkS = "";
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(sentence[i] == ' ' || i == n-1){
                if(i == n-1) checkS += sentence[i];
                cnt++;
                for(int j=0; j<checkS.size(); j++){
                    if(checkS[j] != searchWord[j]){
                        break;
                    }
                    if(j == searchWord.size() - 1){
                        return cnt;
                    }

                }
                checkS = "";
            }
            else{
                checkS += sentence[i];
            }
            
        }
        return -1;
    }
};

/*
using single pass [AC]

tc: o(n)
sc: o(m)
*/
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        string checkS = "";
        int cnt = 1; // Start from 1 to account for the first word
        for (int i = 0; i < n; i++) {
            if (sentence[i] == ' ') {
                checkS = ""; // Reset the word when encountering a space
                cnt++;       // Increment the word count
            } else {
                checkS += sentence[i];
                if (checkS.size() >= searchWord.size() &&
                    checkS.substr(0, searchWord.size()) == searchWord) {
                    return cnt;
                }
            }
        }
        return -1;
    }
};