#define DIRECTIONS 4

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        vector<vector<int>> spiral(rows, vector<int>(cols)), path;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int x=rStart, y=cStart;
        int cur_direction = 0;
        
        while(!x_filled(x, rows, cols, spiral) || !y_filled(x, rows, cols, spiral)){            
            if(in_bound(x, y, rows, cols)){
                spiral[x][y]++;
                path.push_back({x, y});
            }
            auto [dx, dy] = directions[cur_direction];

            x+=dx;
            y+=dy;
            if(is_corner(x, y, rStart, cStart)){
                cur_direction++;
                cur_direction %= DIRECTIONS;
            }
        }
        return path;
    }
private:
    bool x_filled(int x, int rows, int cols, vector<vector<int>>& spiral){
        return x >= 0 && x < rows && spiral[x][0] && spiral[x][cols-1];
    }
    bool y_filled(int y, int rows, int cols, vector<vector<int>>& spiral){
        return y >= 0 && y < cols && spiral[0][y] && spiral[rows-1][y];
    }
    bool in_bound(int x, int y, int rows, int cols){
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }
    bool is_corner(int x, int y, int r, int c){
        if((y < c) && (x < r))
            return y-x == c-r;
        if((y > c) && (x > r))
            return x-y == r-c;
        if(x <= r) x--;
        return r+c == x+y;
    }
};