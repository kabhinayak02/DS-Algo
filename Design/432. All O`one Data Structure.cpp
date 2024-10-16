/*
using unordered map and doubly linked list 

Create a map and stores (keys), (node address) as key-value pair. Create a ddl to stores the count and keys list 
add and remove the node of ddl according to the inc and dec in map 
all the operations will be of tc o(1)

tc: o(1)
sc: o(n)
*/
class AllOne {
private:
    // Create dll node struct
    struct Node {
        int count;
        list<string> keys;
        Node *prev, *next;
        Node(int c) : count(c), prev(NULL), next(NULL) {}
    };

    // Create uordered map to store string and dll node address 
    unordered_map<string, Node*> mp;

    // head->next will stores the min value and tail will stores max value
    Node *head, *tail;

    // to add new node 
    void addNode(Node* prevNode, int count){
        Node* newNode = new Node(count);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if(prevNode->next){
            prevNode->next->prev = newNode;
        }
        prevNode->next = newNode;
        if(tail == prevNode){
            tail = newNode;
        }
    }

    // to delete curr node 
    void removeNode(Node* node){
        node->prev->next = node->next;
        if(node->next){
            node->next->prev = node->prev;
        }
        if(tail == node){
            tail = node->prev;
        }
        delete node;
    }
public:
    AllOne() {
        head = new Node(0);
        tail = head;
    }
    
    void inc(string key) {
        // If key doesn't exist in map 
        if(mp.find(key) == mp.end()){ 
            // If node with count 1 is not exist 
            if(head->next == NULL || head->next->count != 1){ 
                addNode(head, 1); // create new Node with count = 1
            }
            head->next->keys.push_back(key);
            mp[key] = head->next;
        }
        // If key exist in map
        else{ 
            Node* currNode = mp[key];
            int currCount = currNode->count;
            // If next count(freq) node doesn't exist 
            if(currNode->next == NULL || currNode->next->count != currCount+1){
                addNode(currNode, currCount+1); // create new Node with count+1
            }
            currNode->next->keys.push_back(key);
            mp[key] = currNode->next;
            currNode->keys.remove(key);
            // remove currNode if it become empty string(keys)
            if(currNode->keys.empty()){ 
                removeNode(currNode);
            }
        }
    }
    
    void dec(string key) {
        // Assume it already in the map 
        Node* currNode = mp[key];
        int currCount = currNode->count;

        currNode->keys.remove(key);
        // if currCount is 1 means we need to remove entry from the map 
        if(currCount == 1){
            mp.erase(key);
        }
        // we dont need to remove entry bue we need to create new ddl if prev count node is not exsits 
        else{
            if(currNode->prev == head || currNode->prev->count != currCount-1){
                addNode(currNode->prev, currCount-1);
            }
            currNode->prev->keys.push_back(key);
            mp[key] = currNode->prev;
        }

        // delete node if keys list become empty
        if(currNode->keys.empty()){
            removeNode(currNode);
        }
    }
    
    string getMaxKey() {
        // return tail for maxi value 
        return (tail == head) ? "" : tail->keys.front();
    }
    
    string getMinKey() {
        // return head->next for min value
        return (head->next == NULL) ? "" : head->next->keys.front();
    }
};
