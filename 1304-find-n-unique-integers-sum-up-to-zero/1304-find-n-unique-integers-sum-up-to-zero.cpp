class Solution {
public:
    vector<int> sumZero(int n) {
        deque<int> q;
        int count;
        if(n % 2) {
            q.push_back({0});
            count = 1;
        }
        else {
            q.push_back(1);
            q.push_front(-1);
            count = 2;
        }
        
        while(count < n){
            int a = q.front();
            int b = q.back();
            
            q.push_front(--a);
            q.push_back(++b);
            count += 2;
        }
        return vector<int>(q.begin(), q.end());
    }
};