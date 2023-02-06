const int inf = 1e9;

class Solution {
public:
    int racecar(int target) {
        queue<tuple<int, long, int>> q;
        
        q.push({0, 1, 0});
        while(!q.empty()) {
            auto [steps, speed, pos] = q.front();
            q.pop();
            if (pos == target) return steps;
            q.push({steps + 1, speed * 2, pos + speed});
            
            if ((pos + speed > target and speed > 0) ||
                (pos + speed < target and speed < 0)) { // adjustments are needed
                q.push({steps + 1, speed > 0? -1: 1, pos});
            }
        }
        return -1;
    }
};