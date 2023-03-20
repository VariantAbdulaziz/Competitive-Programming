class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        /*
        query = 6
        [[1,7,3]
        ,[2,7,1]
        ,[3,5,1]]
        
        [[2,5,3]
        ,[5,5,7]
        ,[3,5,1]]
        
        [[2,i,6]
        ,[6,i,6]
        ,[6,6,6]]
        
        */
        int n = grid.size(), m = grid[0].size(), k = queries.size();
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> q;
        vector<int> orig_queries = queries;
        vector<vector<int>> visited(n, vector<int>(m));
        vector<array<int, 2>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        map<int, int> book;

        sort(queries.begin(), queries.end());
        q.push({0, 0, 0});
        while(!q.empty()) {
            auto [i, x, y] = q.top(); q.pop();
            if(i < k && queries[i] <= grid[x][y] && !visited[x][y]) {
                i = upper_bound(begin(queries) + i, end(queries), grid[x][y]) - begin(queries);
            }
            if(i == k || visited[x][y]) continue;
            visited[x][y] = queries[i];
            
            for(auto [dx, dy]: dirs) {
                int nx = x + dx;
                int ny = y + dy;
                
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]) {
                    q.push({i, nx, ny});
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                book[visited[i][j]]++;
            }
        }
        int prev_query = 0;
        book[0] = 0;
        int sum = 0;
        for(auto query: queries) {
            if(query != prev_query) {
                sum += book[query];
            }
            book[query] = sum;
            prev_query = query;
        }
        vector<int> result(k);
        for(int i=0; i<k; i++) {
            result[i] = book[orig_queries[i]];
        }
        return result;
    }
};