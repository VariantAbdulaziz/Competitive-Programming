class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1},
                                   {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    
    bool inBound(vector<vector<int>>& board, int i, int j){
        int rows = board.size(), cols = board[0].size();
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }
    int helper(vector<vector<int>>& board, int i, int j){
        int dead_cells = 0, live_cells = 0;
        for(auto [dx, dy]: dirs){
            if(inBound(board, i + dx, j + dy)){
                dead_cells += board[i + dx][j + dy] > 0? 0: 1;
                live_cells += board[i + dx][j + dy] > 0? 1: 0;
            }
        }
        if(!board[i][j]){
            return live_cells == 3? -1: 0;
        }
        return (live_cells < 2 || live_cells > 3)? 2: 1;
    }
    void gameOfLife(vector<vector<int>>& board) {
        
        // 1 -> 0 = 2
        // 0 -> 1 = -1
        
        int rows = board.size(), cols = board[0].size();
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                
                board[i][j] = helper(board, i, j);
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                
                if(board[i][j] == 0 || board[i][j] == 1){
                    continue;
                }
                board[i][j] = board[i][j] == 2? 0: 1;
            }
        }
    }
};