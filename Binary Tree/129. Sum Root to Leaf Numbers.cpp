
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