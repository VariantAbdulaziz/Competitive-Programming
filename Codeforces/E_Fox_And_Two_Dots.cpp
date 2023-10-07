#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(int tc){
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(int r=0; r<n; r++){
        cin >> grid[r];
    }
    vector<vector<int>> book(n, vector<int>(m));
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    auto cycle = [&](auto&& cycle, int r, int c, int pr, int pc){
        if(book[r][c]) return true;

        book[r][c] = 1;
        for(int i=0; i<4; i++){
            int nr = r+dx[i], nc = c+dy[i];
            if((nr == pr && nc == pc) || nr<0 || nc<0 || nr==n || nc==m) continue;
            if(grid[r][c] == grid[nr][nc] && cycle(cycle, nr, nc, r, c)) return true;
        }
        return false;
    };
    for(int r=0; r<n; r++){
        for(int c=0; c<m; c++){
            if(book[r][c]) continue;
            if(cycle(cycle, r, c, -1, -1)) {
                cout << "Yes";
                return;
            }
        }
    }
    cout << "No";
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    for(int i=0; i<t; i++)
        solve(i);
}
