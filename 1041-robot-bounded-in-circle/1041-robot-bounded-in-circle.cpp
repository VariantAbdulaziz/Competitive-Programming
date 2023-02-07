class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<pair<int, int>> directions = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        int idx = 0;
        auto start = make_pair(0, 0);
        auto now = start;
        for (auto instruction: instructions) {
            if (instruction == 'G') {
                auto [dx, dy] = directions[idx];
                auto &[x, y] = now;
                x += dx; y += dy;
            } else if (instruction == 'L') {
                idx += 1;
                idx %= 4;
            } else {
                idx -= 1;
                idx += 4;
                idx %= 4;
            }
        }
        return now == start || idx > 0;
    }
};