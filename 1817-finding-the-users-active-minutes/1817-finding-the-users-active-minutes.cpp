class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int, set<int>> book;
        for (auto log: logs) {
            int id = log[0], time = log[1];
            book[id].insert(time);
        }
        vector<int> answer(k);
        for(auto [id, times]: book) {
            answer[times.size() - 1]++;
        }
        return answer;
    }
};