#include <bits/stdc++.h>

using namespace std;

bool in_bound(vector<string>& grid, vector<int>& curr){
    return curr[0] >= 0 && curr[0] < grid.size() && curr[1] >= 0 && curr[1] < grid[0].size();
}

bool backtrack(vector<string>& grid, vector<vector<int>>& visited, int turn,
                vector<int>& curr, vector<int>& target, vector<int>& dir, vector<vector<int>>& dirs)
                {
    if(turn > 2 || !in_bound(grid, curr) || visited[curr[0]][curr[1]] || grid[curr[0]][curr[1]] == '*'){
        return false;
    }
    if(curr[0] == target[0] && curr[1] == target[1])
        return true;
    
    visited[curr[0]][curr[1]] = 1;
    for(auto target_dir: dirs){
        curr[0] += target_dir[0];
        curr[1] += target_dir[1];
        if(backtrack(grid, visited, turn + (target_dir != dir)? 1: 0, curr, target, target_dir, dirs))
            return true;
        curr[0] -= target_dir[0];
        curr[1] -= target_dir[1];
    }
    visited[curr[0]][curr[1]] = 0;
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int r=0; r<n; r++){
        cin >> grid[r];
    }

    vector<int> home, office;
    vector<vector<int>> visited(n, vector<int>(m));
    for(int r=0; r<n; r++){
        for(int c=0; c<m; c++){
            if(grid[r][c] == 'S'){
                home = {r, c};
            } else if(grid[r][c] == 'T'){
                office = {r, c};
            }
        }
    }

    bool ok = false;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for(auto dir: dirs){
        ok = ok or backtrack(grid, visited, 0, home, office, dir, dirs);
        cout << endl;
    }
    if(ok){
        puts("YES");
    } else {
        puts("NO");
    }
}