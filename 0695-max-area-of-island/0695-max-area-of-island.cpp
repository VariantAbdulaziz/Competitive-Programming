class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> rank(n, vector<int>(m));
        vector<vector<pair<int, int>>> root(n, vector<pair<int, int>>(m));

        auto in_bound = [&](int i, int j){
            return i >= 0 && i < n && j >= 0 && j < m;
        };

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                root[i][j] = {i, j};
                rank[i][j] = grid[i][j];
            }
        }

        auto find = [&](auto&& find, int i, int j) -> pair<int, int>{

            if(root[i][j] != make_pair(i, j)){
                root[i][j] = find(find, (root[i][j]).first, (root[i][j]).second);
            }
            return root[i][j];
        };
        auto cluster = [&](int i, int j, int k, int l){
            auto p0 = find(find, i, j);
            auto p1 = find(find, k, l);
            if(p0 == p1)
                return;

            if (rank[p0.first][p0.second] < rank[p1.first][p1.second])
                swap(p0, p1);

            rank[p0.first][p0.second] += rank[p1.first][p1.second];
            root[p1.first][p1.second] = p0;
        };

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}};
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(auto [dx, dy]: dirs){
                    if(grid[i][j] && in_bound(i+dx, j+dy) && grid[i+dx][j+dy])
                        cluster(i, j, i+dx, j+dy);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max(ans, rank[i][j]);
            }
        }
        return ans;
    }
};