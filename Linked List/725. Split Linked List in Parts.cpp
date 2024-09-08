/*
Linked List 

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* p1 = head;
        int len = 0;
        while(p1 != NULL){
            p1 = p1->next;
            len++;
        }

        vector<ListNode*> ans;

        if(k > len){ // Case 1
            ListNode* curr = head;
            int i = 0;
            while(curr != NULL){
                ListNode* newNode = new ListNode(curr->val);
                ans.push_back(newNode);
                curr = curr->next;
                i++;
            }
            while(i<k){
                ans.push_back(NULL);
                i++;
            }
        }
        else{ // Case 2
            int extraLen = len%k; // 10%3 = 1
            int nodeLen = len/k; // 10/3 = 3
            ListNode* curr = head;

            while(curr != NULL){
                ListNode* dummy = new ListNode(-1);
                ListNode* newHead = dummy;
                int count = nodeLen;
                if(extraLen > 0){
                    count = nodeLen + 1;
                    extraLen--;
                }
                while(curr != NULL && count--){
                    newHead->next = curr;
                    newHead = curr;
                    curr = curr->next;
                }
                newHead->next = NULL; // when count = 0
                ans.push_back(dummy->next);
            }
        }
        return ans;
    }
};