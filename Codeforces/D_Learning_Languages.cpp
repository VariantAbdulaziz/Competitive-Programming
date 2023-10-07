#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int find(int x, vector<int> &par){
    int p = par[x];
    while(p != par[p]){
        par[p] = par[par[p]];
        p = par[p];
    }
    return p;
}

int unite( int p, int q, vector<int> &par, vector<int> &rank){
    int pp = find(p, par);
    int pq = find(q, par);

    if (pp == pq) return 0;
    if(rank[pq] > rank[pp]) swap(pp, pq);
    par[pq] = pp;
    rank[pp] += rank[pq];
    return 1;
}

void solve(){
    int n, m, peepswithnolang = 0; cin >> n >> m;
    vector<vector<int>> adj(m+1);
    for(int i = 1; i <= n; i++){
        int langs; cin >> langs;
        if(langs == 0) peepswithnolang++;
        while(langs--){
            int lang; cin >> lang;
            cout << endl;
            adj[lang].push_back(i);
        }
    }
    vector<int> rank(n+1, 1);
    vector<int> par(n+1); iota(par.begin(), par.end(), 0);
    int components = n;
    for(auto peeps: adj){
        for(int i = 0; i < peeps.size(); i++){
            for(int j = i + 1; j < peeps.size(); j++){
                components -= unite(peeps[i], peeps[j], par, rank);
            }
        }
    }
    if(peepswithnolang == n) components++;
    cout << components - 1 << endl;
}

int main(){
    solve();
}
