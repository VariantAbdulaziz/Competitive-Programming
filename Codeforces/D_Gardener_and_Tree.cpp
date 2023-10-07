#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int t; cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> deg(n+1);
        vector<vector<int>> adj(n+1);

        for(int i=1; i<n; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        queue<int> q;
        for(int i=1; i<=n; i++){
            if(deg[i] <= 1) q.push(i);
        }
        int ans = n;
        while(!q.empty() && k--){
            int l = q.size();
            ans -= l;
            while(l--){
                int node = q.front(); q.pop();
                for(int nei: adj[node]){
                    if(deg[nei] == 1) continue;
                    deg[nei]--;
                    if(deg[nei] == 1) q.push(nei);
                }
            }
        }
        cout << ans << '\n';
    }
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
}
