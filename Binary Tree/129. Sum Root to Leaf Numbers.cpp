
/*
using preorder traversal

tc: O(n)
sc: o(n)

*/
#define ll long long
class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* node, ll temp){
        if(!node) return;
        temp = temp*10 + node->val;
        if(!node->left && !node->right){  
            ans+=temp;
            return;
        }
        if(node->left) dfs(node->left, temp);
        if(node->right) dfs(node->right, temp);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};


/*
different style 

*/
class Solution {
public:
    int solve(TreeNode* root, int curr){
        if(root == NULL) {
            return 0;
        }
        curr = (curr*10) + root->val;
        if(root->left == NULL && root->right == NULL){ // leaf node
            return curr;
        }
        int l = solve(root->left, curr);
        int r = solve(root->right, curr);

        return l + r;

    }
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};