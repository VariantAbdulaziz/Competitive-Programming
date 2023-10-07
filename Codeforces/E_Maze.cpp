#include <bits/stdc++.h>

using namespace std;


int degree(vector<string>& vec, int r, int c, int n, int m){
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int deg = 0;
    for(auto [i, j]: dirs){
        int nr = r+i, nc = c+j;
        if(nr<0 || nc<0 || nr==n || nc==m || vec[nr][nc] != '.')
            continue;
        deg += 1;
    }
    return deg;
}

bool dfs(vector<string>& vec, int n, int m, int check){
    for(int r=0; r<n; r++){
        for(int c=0; c<m; c++){
            if(vec[r][c] == '.' && degree(vec, r, c, n, m) == check){
                vec[r][c] = 'X';
                return true;
            }
        }
    }
    return false;
}

void solve(){
    int n, m, k, s = 0;
    cin >> n >> m >> k;
    vector<string> vec(n);
    for(int r=0; r<n; r++){
        for(int c=0; c<m; c++){
            char temp;
            cin >> temp;
            vec[r].push_back(temp);
        }
    }
    while(k--){
        int check = 1;
        while(!dfs(vec, n, m, check++));
    }
    for(int r=0; r<n; r++){
        cout << vec[r] << '\n';
    }
}
int main(){
    solve();
}