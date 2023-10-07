#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a + b == c){
        puts("+");
    } else {
        puts("-");
    }
}

int32_t main(){
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
