#include <iostream>
#include <queue>

using namespace std;

bool in_bound(int x, int y, int n, int m){
    return x > 0 && x <= n && y > 0 && y <= m;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    queue<pair<int, int>> q;
    vector<vector<int>> burned(n+1, vector<int>(m+1));
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int last_x, last_y;
    for(int i=0; i<k; i++){
        int x, y;
        cin >> x >> y;
        q.push(make_pair(x, y));
        burned[x][y] = 1;
    }
    
    while(!q.empty()){
        int l = q.size();

        while(l--){
            auto [x, y] = q.front(); q.pop();

            for(auto [dx, dy]: directions){
                auto nx = x+dx, ny = y+dy;

                if(in_bound(nx, ny, n, m) && !burned[nx][ny]){
                    q.push(make_pair(nx, ny));
                    burned[nx][ny] = 1;
                }
            }
            last_x = x;
            last_y = y;
        }
    }

    cout << last_x << " " << last_y;

}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    solve();
}