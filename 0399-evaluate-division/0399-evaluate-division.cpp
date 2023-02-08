class Solution {
    double dfs(set<string> &visited, map<string, vector<pair<string, double>>> &adj, string a, string b) {
        if(adj.find(a) == adj.end() || visited.count(a))
            return 0.0;
        
        visited.insert(a);
        double result = 0.0;
        for(auto [next, val]: adj[a]) {
            if (next == b) {
                result = max(result, val);
                break;
            }
            result = max(result, val * dfs(visited, adj, next, b));
        }
        visited.erase(a);
        return result;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        map<string, vector<pair<string, double>>> adj;
        for (int i=0; i<n; i++) {
            string a = equations[i][0], b = equations[i][1];
            double x = values[i];
            
            adj[a].push_back(make_pair(b, x));
            adj[b].push_back(make_pair(a, 1/x));
        }
        vector<double> result;
        set<string> visited;
        for (auto query: queries) {
            string a = query[0], b = query[1];
            auto computation = dfs(visited, adj, a, b);
            result.push_back(computation <= 0.0? -1.0: computation);
        }
        return result;
    }
};