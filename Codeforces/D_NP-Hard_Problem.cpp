#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool dfs(vector<vector<int>>& adj, vector<vector<int>>& colors, vector<int>& marked, int node, int c){
    if(marked[node] != -1) return marked[node] == c;
    marked[node] = c;
    colors[c].push_back(node);
    for(auto nei: adj[node]){
        if(!dfs(adj, colors, marked, nei, 1-c)) return false;
    }
    return true;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> colors(2);
    vector<int> marked(n+1, -1);
    bool flag = false;
    for(int i=1; i<n+1; i++){
        if(marked[i] != -1 || adj[i].empty()) continue;
        if(!dfs(adj, colors, marked, i, 0)){
            cout << "-1"; return;
        }
    }
    for(int i=0; i<2; i++){
        cout << colors[i].size() << '\n';
        for(auto c: colors[i]) cout << c << " ";
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
}