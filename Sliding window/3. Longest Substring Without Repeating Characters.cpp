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

/*
using sliding window 

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