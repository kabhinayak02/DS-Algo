/*

tc: o(k)
sc: o(n.k)
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
        return node->isCompleteWord; 
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char ch : prefix){
            int idx = ch - 'a';
            if(node->children[idx] == NULL) { // if not present 
                return false;
            }
            node = node->children[idx];
        }
        return true;
    }
};