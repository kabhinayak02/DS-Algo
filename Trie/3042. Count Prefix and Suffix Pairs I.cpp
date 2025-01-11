/*
tc: o(n.n)
sc: o(1)
*/
class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2){
        if(str1.size() > str2.size()){
            return false;
        }

        for(int i=0; i<str1.size(); i++){
            if(str1[i] != str2[i]) return false;
        }
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());
        for(int i=0; i<str1.size(); i++){
            if(str1[i] != str2[i]) return false;
        }

        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isPrefixAndSuffix(words[i], words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};

/*
using trie

tc: o(n.n.l)
sc: o(n.l)
*/

class TrieNode{
public:
    bool isCompleteWord;
    TrieNode* children[26];

    TrieNode() {
        isCompleteWord = false; 
        memset(children, 0, sizeof(children)); 
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word){
            int idx = ch - 'a';
            if(node->children[idx] == NULL){ // means we need to create a new trie node for that idx 
                node->children[idx] = new TrieNode();
            } 
            node = node->children[idx];
        }
        node->isCompleteWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(node->children[idx] == NULL){ // if char not present 
                return false;
            } 
            node = node->children[idx];
        }
        return true; 
    }
};
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
    
        for(int j=0; j<n; j++){ // o(n)
            Trie prefixTrie;
            Trie suffixTrie;

            prefixTrie.insert(words[j]); // o(l)
            string rev = words[j];
            reverse(rev.begin(), rev.end()); // o(l)

            suffixTrie.insert(rev);

            for(int i=0; i<j; i++){ // o(n)
                if(words[i].size() > words[j].size()){
                    continue;
                }

                string rev1 = words[i]; 
                reverse(rev1.begin(), rev1.end()); // o(l)

                if(prefixTrie.search(words[i]) == true && suffixTrie.search(rev1) == true){
                    count++;
                }
            }
        }
        return count;
    }
};