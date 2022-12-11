class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph, vector<int>& colors, int node, int color) {
        if(colors[node] != -1)
            return colors[node] == color;
        
        colors[node] = color;
        for(auto nei: graph[node]){
            if(!isBipartite(graph, colors, nei, 1-color))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        for(int node = 0; node < n; node++){
            if(colors[node] == -1 && !isBipartite(graph, colors, node, 0)){
                return false;
            }
        }
        return true;
    }
};