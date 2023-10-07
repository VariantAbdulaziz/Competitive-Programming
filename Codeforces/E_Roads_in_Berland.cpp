#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    ll total = 0;
    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            cin >> grid[r][c];
            total += grid[r][c];
        }
    }
    total /= 2;
    int k;
    cin >> k;
    bool start = true;
    for(int i=0; i<k; i++){
        int a, b, d;
        cin >> a >> b >> d;
        a--, b--;
        if(grid[a][b] > d) total -= (grid[a][b] - d);

        grid[a][b] = min(grid[a][b], d);
        grid[b][a] = min(grid[b][a], d);
        for(int r=0; r<n; r++){
            int prev = grid[a][r];
            int prev2 = grid[b][r];
            grid[a][r] = min(grid[a][r], grid[a][b] + grid[b][r]);
            grid[b][r] = min(grid[b][r], grid[a][b] + grid[a][r]);
            grid[r][a] = min(grid[r][a], grid[a][b] + grid[r][b]);
            grid[r][b] = min(grid[r][b], grid[a][b] + grid[r][a]);

            total -= (prev - grid[a][r]);
            total -= (prev2 - grid[b][r]);
        }
        if(!start) cout << " ";
        cout << total;
        start = false;
    }
}