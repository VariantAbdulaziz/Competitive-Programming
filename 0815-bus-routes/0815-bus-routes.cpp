const int inf = 1e9;

class Solution {
    int dfs(vector<int> &cache, vector<vector<int>> &adj,vector<vector<int>> &routes, int idx, int target) {
        if(find(begin(routes[idx]), end(routes[idx]), target) != routes[idx].end()) {
            return 1;
        }
    
        auto &result = cache[idx];
        if(result != -1) 
            return result;
        
        result = inf;
        for(auto next : adj[idx]) {
            result = min(result, 1 + dfs(cache, adj, routes, next, target));
        }
        return result;
    }
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        int n = routes.size();
        vector<vector<int>> adj(n + 1);
        vector<int> cache(n + 1, -1), source_routes;
        for(int i=0; i<n; i++) {
            set<int> book(begin(routes[i]), end(routes[i]));
            if(book.count(source)) 
                source_routes.push_back(i);
            
            for(int j=i+1; j<n; j++) {
                for(auto station: routes[j]) {
                    if(book.count(station)) {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                        break;
                    }
                }
            }
        }
        int result = inf;
        for(auto s : source_routes) {
            result = min(result, dfs(cache, adj, routes, s, target));
        }
        return result >= inf? -1: result;
    }
};