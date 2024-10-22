/*
using bfs 

tc: o(nlogk)
sc: o(n+k)
*/
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long, vector<long>, greater<long>> pq; // min heap

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            long levelSum = 0;
            while(size--){
                TreeNode* node = q.front();
                q.pop();

                levelSum += node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }

            pq.push(levelSum);
            if(pq.size() > k) pq.pop();

        }
        return pq.size() < k ? -1 : pq.top();
    }
};