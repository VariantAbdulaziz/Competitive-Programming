#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    string password;
    vector<vector<int>> adj(26);

    cin >> password;
    for(int i=0; i<password.size(); i++){
        if(i+1 < password.size()) {
            adj[password[i] - 'a'].push_back(password[i+1] - 'a');
        }
        if(i-1 >= 0) {
            adj[password[i] - 'a'].push_back(password[i-1] - 'a');
        }
    }
    if(no_cycles(adj, i) > 1){
        vector<int> visited(26);
        cout << "YES";
        flow_print(adj, visited);
        return;
    }
    cout << "NO";
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t; cin >> t;
    while(t--)
        solve();
}
