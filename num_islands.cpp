// source: https://leetcode.com/problems/number-of-islands/

// strategy: bfs | queue
class Solution {
private:
    
    bool inRange(int low, int high, int num){
        return low <= num && num < high;
    }
    
    void bfs(vector<vector<char>>& grid, int c, int r){
        
        vector<pair<int, int> > actions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        queue<pair<int, int> > q;
        q.push({c, r});
        while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();
            for(auto action: actions){
                c = action.first + cur.first, r = action.second + cur.second;
                if (inRange(0, grid.size(), c) &&
                    inRange(0, grid[0].size(), r) &&
                    grid[c][r] == '1'){
                    
                    q.push({c, r});
                    grid[c][r] = '0';
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        
        int islands = 0;
        
        for(int c = 0 ; c < grid.size(); c++){
            
            for(int r=0; r < grid[0].size(); r++){
                if(grid[c][r] == '1'){
                    bfs(grid, c, r);
                    islands++;
                }
            }
        }
        
        return islands;
    }
};