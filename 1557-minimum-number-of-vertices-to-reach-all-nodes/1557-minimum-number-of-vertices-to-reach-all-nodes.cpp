class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge: edges) {
            int from = edge[0], to = edge[1];
            adj[to].push_back(from);
        }
        vector<int> result;
        for(int node=0; node<n; node++) {
            if(adj[node].empty()) {
                result.push_back(node);
            }
        }
        return result;
    }
};