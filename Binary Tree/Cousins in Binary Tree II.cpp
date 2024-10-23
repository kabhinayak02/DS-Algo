/*
using level Order traversal (BFS)

tc: o(n)
sc: o(n) worst case
*/
class Solution {
public:
    void reArrangeTree(TreeNode* root, vector<int>& vec, int level, int sublingSum){
        if(root == NULL) return;

        if(level == 0 || level == 1) root->val = 0;
        
        else {
            int levelOrderSum = vec[level];
            root->val = levelOrderSum - sublingSum;
        }

        int childSum = 0;
        if(root->left) childSum += root->left->val;
        if(root->right) childSum += root->right->val;

        if(root->left) reArrangeTree(root->left, vec, level+1, childSum);
        if(root->right) reArrangeTree(root->right, vec, level+1, childSum);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL) return root;
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> levelOrderSumArray;
        while(!q.empty()){
            int size = q.size();
            int levelSum = 0;
            while(size--){
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                levelSum += node->val;
            }
            levelOrderSumArray.push_back(levelSum); 
        }

        // re-arrange the tree
        reArrangeTree(root, levelOrderSumArray, 0, 0);

        return root;
    }
};