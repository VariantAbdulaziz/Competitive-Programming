// source: https://leetcode.com/problems/perfect-squares/

// strategy: bfs | queue
namespace std {
    template <> struct hash<std::pair<int, int>> {
        inline size_t operator()(const std::pair<int, int> &v) const {
            std::hash<int> int_hasher;
            return int_hasher(v.first) ^ int_hasher(v.second);
        }
    };
}

class Solution {
private:
    void populate(unordered_set<pair<int, int> >& visited, queue<pair<int, int> >& q, pair<int, int> state, int n){
        
        int i = 1;
        while(true){
            int square = i*i;
            int pushed = state.first + square;
            if(pushed > n)
                break;
            if(visited.find({pushed, state.second+1}) == visited.end()){
                q.push({pushed, state.second+1});
                visited.insert({pushed, state.second+1});
            }
            i++;
        }
    }
public:
    int numSquares(int n) {
        
        unordered_set<pair<int, int> > visited;
        int squares = 0;
        
        queue<pair<int, int> > q;
        q.push({0, 0});
        while(!q.empty()){
            pair<int, int> state = q.front(); q.pop();

            if (state.first == n)
                return state.second;

            populate(visited, q, state, n);
        }
        return 0;
    }
};