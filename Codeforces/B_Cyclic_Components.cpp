#include <bits/stdc++.h>

using namespace std;

bool cycle(int node, int parent, vector<vector<int>>& adj, vector<int>& visited, vector<int>& cycle_book){
    if(cycle_book[node]){
        return true;
    }
    if(visited[node])
        return false;
    
    visited[node] = 1;
    cycle_book[node] = 1;
    bool result = false;
    for(auto nei: adj[node]){
        if(nei == parent) continue;
        result = result || cycle(nei, node, adj, visited, cycle_book);
    }
    cycle_book[node] = 0;
    return result && adj[node].size() == 2;
}

int main(){
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int result = 0;
    vector<int> visited(n);
    vector<int> cycle_book(n);
    for(int i=0; i<n; i++){
        if(!visited[i] && cycle(i, -1, adj, visited, cycle_book)){
            result++;
        }
    }
    cout << result << endl;
}