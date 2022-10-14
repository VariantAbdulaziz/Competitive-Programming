class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n), adj(n);
        for(auto& e: edges) 
            adj[e[0]].push_back(e[1]);
        
        function<void(int,int)> dfs = [&](int node, int ancestor){
            for (auto& ch: adj[ancestor]) 
                if(ans[ch].size() == 0 || ans[ch].back() != node) {
                    ans[ch].push_back(node);
                    dfs(node, ch);
                }
        };
        for(int node = 0; node < n; node++)
            dfs(node, node);
        return ans;
    }
};