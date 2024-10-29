// Same as 1081. Smallest Subsequence of Distinct Characters 
/*
using visited and last index array 

tc: o(n)
sc: o(26)
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        vector<bool> vis(26, false);
        vector<int> lastIndex(26, -1);

        for(int i = 0; i < n; i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        string ans = "";
        for(int i = 0; i < n; i++) {
            if(vis[s[i] - 'a']) {
                continue;  // Skip already visited characters
            }
            
            // Remove characters from `ans` while the current character is smaller than the last character
            // and there are more occurrences of the last character in `ans` later in the string
            while(!ans.empty() && ans.back() > s[i] && lastIndex[ans.back() - 'a'] > i) {
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            
            // Now add the current character to the result and mark it as visited
            ans += s[i];
            vis[s[i] - 'a'] = true;
        }
        
        return ans;
    }

};

/*
using freq array and vis array 

tc: o(n)
sc: o(26)
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0), vis(26, 0);
        string ans = "";
        int n = s.size();
        for(int i=0; i<n; i++){
            count[s[i] - 'a']++;
        }

        for(int i=0; i<n; i++){
            count[s[i] - 'a']--;
            if(!vis[s[i] - 'a']){
                while(ans.size() > 0 && ans.back() > s[i] && count[ans.back() - 'a'] > 0){
                    vis[ans.back() - 'a'] = 0;
                    ans.pop_back();
                }
                ans += s[i];
                vis[s[i] - 'a'] = 1;
            }
        }
        return ans;
    }
};