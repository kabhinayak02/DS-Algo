/*
level order traversal + count swapping required 

tc: o(n)
sc: o(w) where w is max width of tree
*/
class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++) {
            mp[nums[i]] = i;
        }
        
        vector<int> nums1 = nums;
        sort(nums1.begin(), nums1.end());
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == nums1[i]) continue; // no swap needed 
            
            int j = mp[nums1[i]];  // Get index of where current element should go
    
            // Update the map with new positions before swapping
            mp[nums[i]] = j;
            mp[nums[j]] = i;
            
            // Perform the swap
            swap(nums[i], nums[j]);
            
            ans++;
        }
        return ans;
    }
    
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root); 
        int ans = 0;
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> vec;
            while(size--) {
                TreeNode* node = q.front();
                q.pop();
                vec.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans += solve(vec);
        }
        return ans;
    }
};