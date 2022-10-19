#define DIRECTIONS 4

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        vector<vector<int>> path;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int x=rStart, y=cStart;
        int cur_direction = 0;
        int populated = 1;
        
        while(populated <= (rows*cols)){            
            if(in_bound(x, y, rows, cols)){
                populated++;
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