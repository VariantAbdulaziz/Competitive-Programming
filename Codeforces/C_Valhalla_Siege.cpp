#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<ll> a(n+1);
    vector<ll> pr(n+1);

    for(int i=1; i<n+1; i++){
        cin >> a[i];
    }
    for(int i=1; i<n+1; i++){
        pr[i] = pr[i-1] + a[i];
    }
    int i = 0;
    ll sum = 0;
    while(q--){
        ll query; cin >> query;
        sum += query;
        int idx = 0;
        for(int j=n/2; j>0; j/=2){
            while(idx + j <= n && pr[idx + j] <= sum) idx += j;
        }
        if(idx >= n) {
            idx = 0;
            sum = 0;
        }
        cout << n - idx << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
}