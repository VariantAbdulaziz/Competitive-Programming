// source: https://leetcode.com/problems/open-the-lock/

// strategy: bfs | queue
class Solution {
private:
    string result(string state, pair<int, int> action){
        
        int change = state[action.first] - '0';
        state[action.first] = '0' + ((change + action.second + 10) % 10);
        return state;
    }
    int bfs(string init, string goal, vector<string>& deadends){
        
        int moves = 0;
        unordered_set<string> visited;
        vector<pair<int, int> > actions = {
            {0, 1}, {0, -1},
            {1, 1}, {1, -1},
            {2, 1}, {2, -1},
            {3, 1}, {3, -1},
        };
        
        queue<string> q;
        q.push(init);
        while(!q.empty()){
            
            int lvl = q.size();
            
            while(lvl > 0) {
                string state = q.front();
                q.pop();

                if(state == goal)
                    return moves;

                for(auto action: actions){
                    string new_state = result(state, action);
                    if(visited.find(new_state) == visited.end() &&
                      find(deadends.begin(), deadends.end(), new_state) == deadends.end()){
                        q.push(new_state);
                        visited.insert(new_state);
                    }
                }
                lvl--;
            }
            moves++;
        }
        return -1;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        
        if(find(deadends.begin(), deadends.end(), "0000") != deadends.end())
            return -1;
        
        int moves = bfs("0000", target, deadends);
        
        return moves;
    }
};