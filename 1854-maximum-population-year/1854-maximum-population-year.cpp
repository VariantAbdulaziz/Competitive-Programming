class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> populations(100 + 5);
        for(auto log: logs) {
            populations[log[0] - 1950]++;
            populations[log[1] - 1950]--;
        }
        int commulative = 0, n = populations.size();
        int idx = 0, _max = 0;
        for(int i=0; i<n; i++) {
            commulative += populations[i];
            if (commulative > _max) {
                 idx = i;
                _max = commulative;
            }
        }
        return 1950 + idx;
    }
};