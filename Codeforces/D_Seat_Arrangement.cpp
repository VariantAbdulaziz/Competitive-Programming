#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i=0; i<n; i++) {
        cin >> grid[i];
    }
    int ans = 0;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == '#') {
                for(auto [dx, dy]: dirs) {
                    int ni = i + dx, nj = j + dy;
                    if(ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == '.' && !visited[ni][nj]) {
                        ans++;
                        visited[ni][nj] = 1;
                    }
                }
            } else if ((i == 0 || j == 0 || i + 1 == n || j + 1 == m) && !visited[i][j]) {
                ans++;
                visited[i][j] = 1;
            }
        }
    }
    cout << ans << endl;
}

int32_t main(){
    solve();
}
