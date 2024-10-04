/*

GFG Link: https://www.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1

tc: o(n)
sc: o(1)c

*/

Node* reverse(Node* head) {
    if (head == NULL || head->next == head)  // empty or single node
        return head;

    Node *prev = NULL, *curr = head, *next = NULL;
    Node *newTail = head;  // head will become the new tail
    
    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != head);  // stop when we've completed one loop

    // Make the new head's next point back to the old head (now tail)
    newTail->next = prev;

    return prev;  // prev is the new head
}


Node* deleteNode(Node* head, int key) {
    if (head == NULL) return NULL;

    Node* curr = head;
    Node* prev = NULL;

    // If head itself holds the key
    if (head->data == key) {
        // If there's only one node in the list
        if (head->next == head) {
            delete head;
            return NULL;
        }

        // Find the last node to fix the circular link
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        
        // Make the last node point to the new head
        last->next = head->next;
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    // Traverse the list to find the node to be deleted
    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == key) {
            prev->next = curr->next;
            delete curr;
            return head;
        }
    } while (curr != head);  // Stop when we have looped back to the head

    // If the key was not found, return the original head
    return head;
}
