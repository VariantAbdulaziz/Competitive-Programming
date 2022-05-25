// source: https://leetcode.com/problems/design-circular-queue/

// strategy: ad hoc solution
class MyCircularQueue {
private:
    int f, r, cap, size, *cir_q;
public:
    MyCircularQueue(int k) 
    : f{}, r{}, size{}, cap{k}{
        cir_q = new int[cap];
    }
    
    bool enQueue(int value) {
        
        if(!isFull()){
            cir_q[r] = value;
            r = (r + 1) % cap;
            size++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        
        if(!isEmpty()){
            f = (f + 1) % cap;
            size--;
            return true;
        }
        return false;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return cir_q[f];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return cir_q[(r-1 + cap)%cap];
    }
    
    bool isEmpty() {
        
        return size == 0;
    }
    
    bool isFull() {
        
        return size == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */