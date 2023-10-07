#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    int l=0, r=n-1;
    while(l < r && s[l] == s[r]) l++, r--;
    while(l < r && s[l] != s[r]) l++, r--;
    while(l < r && s[l] == s[r]) l++, r--;
    if(l >= r) {
        puts("Yes");
    } else puts("No");
}

int32_t main(){
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
