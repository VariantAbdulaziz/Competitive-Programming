class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>> adj;
        map<int, int> degree;
        for(auto &pair: adjacentPairs){
            degree[pair[0]]++;
            degree[pair[1]]++;
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        int start;
        for(auto [num, deg]: degree) {
            if(deg == 1) start = num;
        }
        vector<int> restored_array;
        set<int> explored;
        int now = start;
        while(!explored.count(now)) {
            explored.insert(now);
            restored_array.push_back(now);
            for(auto next: adj[now]){
                if(!explored.count(next)){
                    now = next;
                }
            }
        }
        return restored_array;
    }
};