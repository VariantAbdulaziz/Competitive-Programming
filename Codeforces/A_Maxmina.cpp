#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(int tc){
    int n, k, s = 0;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int aj; cin >> aj;
        s += aj;
    }
    if(s > 0) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve(i);
}
