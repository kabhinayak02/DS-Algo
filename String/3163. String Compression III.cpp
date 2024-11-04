/*
using string traversal 

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        string comp = "";

        int i = 0;

        while(i < n){
            int count = 0;
            char ch = word[i];

            while(i < n && count < 9 && word[i] == ch){
                count++;
                i++;
            }

            comp += to_string(count) + ch;
        }

        return comp;
    }
};