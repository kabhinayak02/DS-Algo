/*

Gfg Link: https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1

tc: o(n)
sc: o(h), h -> height of the tree, in best case o(logn)
*/

class Solution {
private:
    Node* prev = NULL;
    
    void solve(Node* root, Node* &head){
        if(root==NULL){
            return;
        }
        solve(root->left, head);
        if(prev==NULL){
            head = root;
        }
        else{
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        solve(root->right, head);
    }
public:
    Node * bToDLL(Node *root)
    {
        Node* head = NULL;
        solve(root, head);
        return head;
        
    }
};