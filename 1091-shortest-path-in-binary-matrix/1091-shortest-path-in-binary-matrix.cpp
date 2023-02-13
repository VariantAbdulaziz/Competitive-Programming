class Solution {
    bool valid(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]) return -1;
        
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {1,-1}, {-1,-1}, {-1,1}};
        queue<pair<int, int>> q;
        q.push({0, 0});
        set<pair<int, int>> visited;
        int path = 1;
        while(!q.empty()) {
            int l = q.size();
            while(l--) {
                auto [x, y] = q.front(); q.pop();
                if(x==n-1 && y==m-1) {
                    return path;
                }

                for(auto [dx, dy]: dirs) {
                    x += dx; y += dy;
                    if(valid(x, y, n, m) && !visited.count({x, y}) && !grid[x][y]){
                        q.push({x, y});
                        visited.insert(make_pair(x, y));
                    }
                    x -= dx; y -= dy;
                }
            }
            path += 1;
        }
        return -1;
    }
};