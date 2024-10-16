/*
using vector

tc: o(1)
sc: o(n)
*/
class MyCircularDeque {
private:
    vector<int> deq;
    int K;
    int front;
    int rear;
    int currCount;
public:
    MyCircularDeque(int k) {
        K = k;
        deq = vector<int>(k, 0);
        front = 0;
        rear = k-1;
        currCount = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;

        front = (front-1+K)%K;
        deq[front] = value;
        currCount++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;

        rear = (rear+1)%K;
        deq[rear] = value;
        currCount++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;

        front = (front+1)%K;
        currCount--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;

        rear = (rear-1+K)%K;
        currCount--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return deq[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return deq[rear];
    }
    
    bool isEmpty() {
        return currCount == 0;
    }
    
    bool isFull() {
        return currCount == K;
    }
};
