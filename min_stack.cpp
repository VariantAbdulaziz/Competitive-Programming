// source: https://leetcode.com/problems/min-stack/

// policy: linear search
class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        minStack.push_back(val);
    }
    
    void pop() {
        minStack.pop_back();
    }
    
    int top() {
        return minStack.back();
    }
    
    int getMin() {
        int m = INT_MAX;
        for(auto val: minStack)
            m = min(m, val);
        return m;
    }
private:
    vector<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */