#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1e18;

void solve(){
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    vector<vector<ll>> cache(n+1, {INF, INF});

    cache[0][0] = b;
    for(int i=0; i<n; i++){
        if(s[i] == '0'){
            cache[i+1][0] = min(cache[i][1] + 2*a + b, cache[i][0] + a + b);
            cache[i+1][1] = min(cache[i][0] + 2*(a + b), cache[i][1] + a + 2*b);
        } else {
            cache[i+1][1] = min(cache[i+1][1], cache[i][1] + a + 2*b);
        }
    }
    cout << cache[n][0] << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}