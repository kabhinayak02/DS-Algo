/*
DFS Approach 

using same logic as Leetcode 2415

tc: o(n)
sc: o(n)

*/
class Solution {
public: 
    bool solve(TreeNode* R, TreeNode* L){
        if(R == NULL && L == NULL){
            return true;
        }
        if(R == NULL || L == NULL){
            return false;
        }

        if(R->val != L->val){
            return false;
        }

        return solve(L->left, R->right) && solve(L->right, R->left);
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }
};