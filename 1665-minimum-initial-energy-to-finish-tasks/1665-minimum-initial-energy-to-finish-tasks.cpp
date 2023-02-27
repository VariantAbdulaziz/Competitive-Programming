class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int minimum_effort = 0;
        sort(tasks.begin(), tasks.end(), [](auto a, auto b){
            int adiff = a[1] - a[0], bdiff = b[1] - b[0];
            return adiff < bdiff || (adiff == bdiff && a[1] < b[1]);
        });
        for (auto &task : tasks)
            minimum_effort = max(minimum_effort + task[0], task[1]);
        return minimum_effort;
    }
};