class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int start_x, start_y, empty_count = 0;
        vector<vector<char>> visited(n, vector<char>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    start_x = i, start_y = j;
                }
                if(grid[i][j] == 0){
                    empty_count++;
                }
            }
        }
        return uniquePathsIII(grid, visited, start_x, start_y, empty_count);
    }
    
    bool inBound(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid, vector<vector<char>>& visited, int x, int y, int empty_count){
        int n = grid.size(), m = grid[0].size();
        if(!inBound(x, y, n, m) || visited[x][y] || grid[x][y] == -1){
            return 0;
        }
        if(grid[x][y] == 2){
            return empty_count == -1? 1: 0;
        }
        int result = 0;
        visited[x][y] = 1;
        result += uniquePathsIII(grid, visited, x + 1, y, --empty_count);
        result += uniquePathsIII(grid, visited, x - 1, y, empty_count);
        result += uniquePathsIII(grid, visited, x, y + 1, empty_count);
        result += uniquePathsIII(grid, visited, x, y - 1, empty_count);
        visited[x][y] = 0;
        return result;
    }
};