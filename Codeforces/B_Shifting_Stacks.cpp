#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &aj: a) cin >> aj;

    ll pushed = 0, prev = -1;
    for(int i=0; i<n; i++){
        a[i] += pushed;
        if(a[i] <= prev){
            cout << "NO\n";
            return;
        } else {
            prev++;
            pushed = a[i] - prev;
        }
    }
    cout << "YES\n";
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
        solve();
}
