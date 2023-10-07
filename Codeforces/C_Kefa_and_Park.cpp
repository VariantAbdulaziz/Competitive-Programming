#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dfs(vector<vector<int>>& adj, vector<int>& contains_cats, int m, int node, int cats_count, int prev){
    int res = 0;
    bool leaf = true;
    for(auto nei: adj[node]){
        if(nei != prev) {
            if(!contains_cats[node]) cats_count = 0;
            res += dfs(adj, contains_cats, m, nei, cats_count + contains_cats[nei], node);
            leaf = false;
        }
    }
    if(leaf && cats_count <= m) return 1;
    if(leaf) return 0;
    if(cats_count <= m) return res;
    return 0;
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> contains_cats(n+1);
    vector<vector<int>> adj(n+1);

    for(int i=1; i<=n; i++){
        cin >> contains_cats[i];
    }
    for(int i=1; i<n; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << dfs(adj, contains_cats, m, 1, contains_cats[1], -1);

}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    solve();
}
