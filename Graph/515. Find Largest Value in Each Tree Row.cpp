/*
using level order traversal (BFS)

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            int size = q.size();
            int ele = INT_MIN;
            while(size--){
                TreeNode* node = q.front();
                q.pop();

                ele = max(ele, node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(ele);
        }
        return ans;
    }

};