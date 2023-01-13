class Solution {
public:
    int dfs(int& longest_path, vector<vector<int>>& adj, string& s, int root){
        vector<int> pool;
        for(auto child: adj[root]){
            auto ret = dfs(longest_path, adj, s, child);
            if(s[child] != s[root]) pool.push_back(ret);
        }
        sort(rbegin(pool), rend(pool));
        if(adj[root].empty() || pool.empty()){
            return 1;
        } else if(pool.size() == 1){
            longest_path = max(longest_path, pool[0] + 1);
        } else {
            longest_path = max(longest_path, pool[0] + pool[1] + 1);
        }
        return 1 + pool[0];
    }
    int longestPath(vector<int>& parent, string s) {
        int root = -1, longest_path = 1;
        vector<vector<int>> adj(parent.size());
        for(int i=0; i < parent.size(); i++) {
            if(parent[i] != -1) {
                adj[parent[i]].push_back(i);
            } else root = i;
        }
        
        dfs(longest_path, adj, s, root);
        return longest_path;
    }
};