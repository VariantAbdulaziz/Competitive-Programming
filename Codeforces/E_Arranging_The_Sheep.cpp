#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<int> pr(n+1), su(n+1);
    pr[0] = 0; su[n] = 0;
    for(int i=0; i<n; i++){
        pr[i+1] = pr[i] + (s[i] == '*'? 1: 0);
    }
    for(int i=n; i>0; i--){
        su[i-1] = su[i] + (s[i] == '*'? 1: 0);
    }
    ll result = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '.')
            result += min(pr[i], su[i]);
    }
    printf("%lld\n", result);
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}