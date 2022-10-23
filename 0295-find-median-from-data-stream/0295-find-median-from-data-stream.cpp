class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        before.push(num);
        
        if(!before.empty() && !after.empty() && before.top() > after.top()){
            int shifted = before.top();
            before.pop();
            after.push(shifted);
        }
        if(before.size() > after.size() + 1){
            int shifted = before.top();
            before.pop();
            after.push(shifted);
        }
        if(after.size() > before.size() + 1){
            int shifted = after.top();
            after.pop();
            before.push(shifted);
        }
    }
    
    double findMedian() {
        if(before.size() == after.size()){
            return (before.top() + after.top())/2.0;
        }
        if(before.size() > after.size()) return before.top();
        return after.top();
    }
    
    priority_queue<int> before;
    priority_queue<int, vector<int>, greater<int>> after;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */