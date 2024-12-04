/*
2 pointer approach  

Same as leetcode 392 : https://leetcode.com/problems/is-subsequence/

use 2 pointer on both the string and check for the same char or char+1 and move the pointer.

tc: o(n+m)
sc: o(n)
*/
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();

        int i = 0, j = 0;

        while(i < n && j < m){
            if(str1[i] == str2[j] || str1[i]+1 ==  str2[j] || ((str1[i] == 'z') && str2[j] == 'a')){
                j++;
                i++;
            }
            else{
                i++;
            }
        }
        return j == m;
    }
};