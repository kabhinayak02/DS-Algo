
// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    private:
    void inorder(Node* root, vector<int> &v){
        if(root==NULL){
            return;
        }
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    
    vector<int> mergeArrays(vector<int> &a,vector<int> &b){
        vector<int> ans(a.size() + b.size());
        int i=0;
        int j=0;
        int k=0;
        while(i < a.size() && j < b.size()){
            if(a[i]<b[j]){
                ans[k++] = a[i];
                i++;
            }
            else{
                ans[k++] = b[j];
                j++;
            }
        }
        while(i<a.size()){
            ans[k++] = a[i];
            i++;
        }
        while(j<b.size()){
            ans[k++] = b[j];
            j++;
        }
        return ans;
    }

    // to build the bst from the sorted array but we don't need in this problem so skip this code block
    Node* toBst(int s, int e, vector<int> &in){
        if(s>e){return NULL;}
        int m = (e+s)/2;
        Node* root = new Node(in[m]);
        root->left = toBst(s, m-1, in);
        root->right = toBst(m+1, e, in);
        return root;
    }    
     
    public:
    vector<int> merge(Node *root1, Node *root2)
    {
       vector<int> bst1, bst2;
       inorder(root1, bst1);
       inorder(root2, bst2);
       
       return mergeArrays(bst1, bst2);
       //return toBst(0, mergeArray.size()-1, mergeArray);
    }
};

