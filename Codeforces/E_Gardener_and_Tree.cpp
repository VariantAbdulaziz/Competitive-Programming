#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    vector<int> degree(n);

    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    queue<int> q;
    for(int i=0; i<n; i++){
        if(degree[i] <= 1){
            q.push(i);
        }
    }
    int result = n;
    while(k-- && !q.empty()){
        int level = q.size();
        while(level--){
            result--;
            auto leaf = q.front(); q.pop();
            for(auto node: adj[leaf]){
                degree[node]--;
                if(degree[node] == 1){
                    q.push(node);
                }
            }
        }
    }
    cout << result << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}