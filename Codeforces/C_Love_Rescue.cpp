#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    string a, b;
    cin >> a >> b;
    for(int i=0; i<n; i++){
        adj[a[i]].push_back(b[i]);
    }

}

int main(){
    solve();
}