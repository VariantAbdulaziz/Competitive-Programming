// source: https://leetcode.com/problems/implement-queue-using-stacks/

// strategy: stack
class MyQueue {
public:
    MyQueue() {
        stack<int> first;
        stack<int> second;
    }
    
    void push(int x) {
        first.push(x);
    }
    
    int pop() {
        while(!first.empty()){
            second.push(first.top());
            first.pop();
        }
        int popped = second.top();
        second.pop();
        while(!second.empty()){
            first.push(second.top());
            second.pop();
        }
        return popped;
    }
    
    int peek() {
        while(!first.empty()){
            second.push(first.top());
            first.pop();
        }
        int popped = second.top();
        while(!second.empty()){
            first.push(second.top());
            second.pop();
        }
        return popped;
    }
    
    bool empty() {
        return first.empty();
    }
private:
    stack<int> first;
    stack<int> second;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */