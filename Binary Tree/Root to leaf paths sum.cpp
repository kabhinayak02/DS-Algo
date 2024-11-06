/*

gfg link: https://www.geeksforgeeks.org/problems/root-to-leaf-paths-sum/1

using preorder traversal 

tc: o(n)
sc: o(n)
*/

class Solution {
  public:
    void preorder(Node* root, int &ans, int curr){
        if(root==NULL){
            return;
        }
        curr=curr*10 + root->data;
        if(root->left==NULL && root->right==NULL){
            ans+=curr;
            return;
        }
        preorder(root->left, ans, curr);
        preorder(root->right, ans, curr);
    }
    
    int treePathsSum(Node *root) {
        int ans = 0;
        int curr = 0;
        preorder(root,ans,curr);
        return ans;
    }

};