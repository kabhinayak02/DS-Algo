/*
using sliding window (More intuitive than below solution)

2 pointer approach (sliding variable size window): move j in string s and check if it is already present in the set, if yes then remove the 
element from the last by moving i'th index untill the set became unique again (by this we are making window unique too), now add j'th index 
element add move to next iteration till the string is exhausted. 

Although it looks like we are using 2 nested loops, so the time complexity is o(n.n) but we actually visiting the each element only 2 times 
each one if for add and for remove atmost. So, time complexity still be o(n + n) -> o(n).

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int maxSize = 0;
        int i=0, j=0;
        while(j < s.size()){
            while(chars.find(s[j]) != chars.end()){ // iterate till set become unique again by moving i.
                chars.erase(s[i]);
                i++;
            }
            maxSize = max(maxSize, j-i+1);
            chars.insert(s[j]);
            j++;
        }
        return maxSize;
    }
};

/*
using sliding window 

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        unordered_set<char> st;
        int ans = 0;
        
        while (j < s.size()) {
            // If the character is not in the set, insert it and update the answer
            if (st.find(s[j]) == st.end()) {
                st.insert(s[j]);
                ans = max(ans, j - i + 1);
                j++;
            } else {
                // If the character is in the set, remove the characters from the start until it is not
                st.erase(s[i]);
                i++;
            }
        }
        
        return ans;
    }
};