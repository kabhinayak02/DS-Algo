/*

tc: o(n), traversing
sc: o(n), using map 

*/

class Solution {
  public:
    int intersectPoint(Node* head1, Node* head2) {
        unordered_map<Node*, int> mp;
        
        while(head1!=NULL){
            mp[head1] = head1->data;
            head1 = head1->next;
        }
        
        while(head2!=NULL){
            if(mp.find(head2) != mp.end()){
                return head2->data;
            }
            head2 = head2->next;
        }
        return -1;
    }
};