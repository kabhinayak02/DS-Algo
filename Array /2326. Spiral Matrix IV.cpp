/*
Use 4 pointer, top, down, right and left.

tc: o(n.m)
sc: o(n.m)
*/
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> ans(m, vector<int> (n, -1));
        int id = 0;
        int top = 0, down = m-1, left = 0, right = n-1;

        while(top <= down && left <= right){
            if(id == 0){
                for(int i=left; head!=NULL && i<=right; i++){
                    ans[top][i] = head->val;
                    head = head->next;
                }
                top++;
            }

            if(id == 1){
                for(int i=top; head!=NULL && i<=down; i++){
                    ans[i][right] = head->val;
                    head = head->next;
                }
                right--;

            }
            if(id == 2){
                for(int i = right; head != NULL && i>=left; i--){
                    ans[down][i] = head->val;
                    head = head->next;
                }
                down--;
            }
            if(id == 3){
                for(int i=down; head != NULL && i>=top; i--){
                    ans[i][left] = head->val;
                    head = head->next;
                }   
                left++;
            }
            id = (id+1)%4;
            
        }
        return ans;
    }
};