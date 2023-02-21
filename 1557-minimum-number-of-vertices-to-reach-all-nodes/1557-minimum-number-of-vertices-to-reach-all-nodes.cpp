class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> adj(n);
        for(auto edge: edges) {
            int from = edge[0], to = edge[1];
            adj[to]++;
        }
        vector<int> result;
        for(int node=0; node<n; node++) {
            if(!adj[node]) {
                result.push_back(node);
            }
        }
        return result;
    }
};