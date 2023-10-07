#include <bits/stdc++.h>
#define int int64_t

using namespace std;

bool equiv(string a, string b) {
    int n = a.size();
    if(a == b) return true;
    if(a.size() % 2 || b.size() % 2) return false;

    string a1 = a.substr(0, n / 2), a2 = a.substr(n / 2);
    string b1 = b.substr(0, n / 2), b2 = b.substr(n / 2);
    bool result = (equiv(a1, b1) && equiv(a2, b2)) || (equiv(a1, b2) && equiv(a2, b1));
    return result;
}

void solve(){
    string a, b;
    cin >> a >> b;
    map<string, bool> cache;
    if(equiv(a, b)) puts("YES");
    else puts("NO");
}

int32_t main(){
    solve();
}
