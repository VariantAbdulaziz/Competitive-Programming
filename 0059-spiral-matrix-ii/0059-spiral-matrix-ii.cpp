class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        const int DIRECTIONS = 4;
        vector<vector<int>> spiral_matrix(n, vector<int>(n, -1));
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x=0;
        int y=0;
        int cur_direction=0;
        int to_be_populated = 1;
        
        while(in_bound(x, y, n) && !is_populated(x, y, spiral_matrix)){
            auto [dx, dy] = directions[cur_direction];

            while(in_bound(x, y, n) && !is_populated(x, y, spiral_matrix)){
                spiral_matrix[x][y] = to_be_populated++;
                x += dx;
                y += dy;
            }
            // retracting our last update to x and y
            x -= dx;
            y -= dy;
            
            // change direction
            cur_direction = (cur_direction + 1) % DIRECTIONS;
            dx = directions[cur_direction].first;
            dy = directions[cur_direction].second;
            
            // update x and y with next direction
            x += dx;
            y += dy;
        }
        
        return spiral_matrix;
    }
private:
    bool in_bound(int x, int y, int n){
        return x >=0 && x < n && y >= 0 && y < n;
    }
    bool is_populated(int x, int y, vector<vector<int>>& spiral_matrix){
        return spiral_matrix[x][y] != -1;
    }
};