/*
using slow, fast and do-while loop 

tc: o(n)
sc: o(2)
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode *slow = head, *fast = head;
        do {
            if(fast->next == NULL || fast->next->next == NULL) return NULL;
            fast = fast->next->next;
            slow = slow->next;
        } while(fast != slow);

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};


/*
using slow, fast and while loop 

tc: o(n)
sc: o(2)
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode *slow = head, *fast = head;
        while (true) {
            if (fast == NULL || fast->next == NULL) {
                return NULL; // No cycle
            }
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                break; // Cycle detected
            }
        }

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};