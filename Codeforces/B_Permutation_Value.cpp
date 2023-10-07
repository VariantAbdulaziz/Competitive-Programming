#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



void solve(){
    int n;
    cin >> n;

    cout << 1;
    for(int i=n; i>1; i--){
        cout << " " << i;
    }
    cout << "\n";
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
