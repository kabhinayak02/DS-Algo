/*
using level order traversal

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    TreeNode* constructBinaryTree(vector<int>& vec, int idx, int n){
        if(idx >= n) return NULL;

        TreeNode* node = new TreeNode(vec[idx]);

        node->left = constructBinaryTree(vec, 2*idx+1, n);
        node->right = constructBinaryTree(vec, 2*idx+2, n);

        return node;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> que;
        que.push(root);

        vector<int> vec;

        while(!que.empty()){
            int size = que.size();
            vector<int> temp;
            while(size--){
                TreeNode* node = que.front();
                que.pop();

                temp.push_back(node->val);

                if(node->left){
                    que.push(node->left);
                }   
                if(node->right){
                    que.push(node->right);
                } 

            }
            if(level%2 != 0) {
                reverse(temp.begin(), temp.end());
            }
            for(auto i: temp) vec.push_back(i);
            level++;
        }
        int n = vec.size();
        TreeNode* newRoot = constructBinaryTree(vec, 0, n);
        return newRoot;
    }
};

/*
In-place swapping using level order traversal (BFS)

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*> vec; // level order nodes 

            while(size--){
                TreeNode* node = q.front();
                q.pop();
                vec.push_back(node);

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(level%2 == 1){ // odd level;
                int i = 0;
                int j = vec.size()-1;
                while(i < j){
                    int nodeVal = vec[i]->val;
                    vec[i]->val = vec[j]->val;
                    vec[j]->val = nodeVal;
                    i++;
                    j--;
                }
            }
            level++;
        }
        return root;
    }
};

/*
using DFS

using same logic as Leetcode 101

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    void solve(TreeNode* L, TreeNode* R, int level){
        if(L == NULL || R == NULL){
            return;
        }

        if(level%2 == 1){
            int nodeVal = L->val;
            L->val = R->val;
            R->val = nodeVal;
        }
        
        solve(L->left, R->right, level+1);
        solve(L->right, R->left, level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root->left, root->right, 1);
        return root;
    }
};