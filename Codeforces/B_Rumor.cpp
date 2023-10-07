#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dfs (vector<ll>& c, vector<int>& visited, vector<vector<int>>& adj, int node){
    visited[node] = 1;
    ll res = c[node];
    for(auto nei: adj[node]){
        if(visited[nei]) continue;
        res = min(res, dfs(c, visited, adj, nei));
    }
    return res;
};

void solve(){
    int n, m;
    cin >> n>> m;
    vector<ll> c(n+1);
    vector<vector<int>> adj(n+1);
    vector<int> visited(n+1);
    
    for(int j=1; j<n+1; j++){
        cin >> c[j];
    }
    for(int i=0; i<m; i++){
        int p, q;
        cin >> p >> q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }
    ll ans = 0;
    for(int i=1; i<n+1; i++){
        if(visited[i]) continue;
        ans += dfs(c, visited, adj, i);
    }
    cout << ans;
}

int main(){
    solve();
}