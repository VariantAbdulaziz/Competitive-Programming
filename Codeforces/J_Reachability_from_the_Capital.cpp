#include <bits/stdc++.h>

using namespace std;

int reachable(vector<vector<int>>& adj, vector<int>& bad, const vector<int>& good, int s){

    bad[s] = 1;
    int result = 1;
    for(auto c: adj[s]){
        if(good[c] || bad[c]) continue;
        result += reachable(adj, bad, good, c);
    }
    return result;
}

int main(){
    int n, m, s;
    cin >> n >> m >> s;
    vector<int> good_bunch(n), bad_bunch(n);
    vector<vector<int>> adj(n);

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    int result = INT_MAX;
    int g_reachable = reachable(adj, good_bunch, good_bunch, s-1);
    for(int i=0; i<n; i++){
        if(good_bunch[i]) continue;
        for(auto &c: bad_bunch) c = 0;
        int b_reachable = reachable(adj, bad_bunch, good_bunch, i);
        result = min(result, n - g_reachable - b_reachable + 1);
    }
    cout << result;
}