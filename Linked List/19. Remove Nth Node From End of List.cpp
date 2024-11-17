/*
using linked list traversal

tc: o(n+n)
sc: o(2)
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Calculate the length of the list
        int len = 0;
        ListNode* p1 = head;
        while(p1){
            p1 = p1->next;
            len++;
        }
        
        // Special case: Removing the head node
        if(n == len) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        // Find the node just before the target node
        p1 = head;
        int targetNode = len - n - 1;
        for(int i = 0; i < targetNode; i++){
            p1 = p1->next;
        }
        
        // Remove the target node
        ListNode* nodeToRemove = p1->next;
        p1->next = p1->next->next;
        delete nodeToRemove;
        
        return head;
    }
};