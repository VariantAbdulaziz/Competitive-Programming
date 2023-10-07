#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve(){
    int n;
    cin >> n;
    set<string> book;
    for(int i=0; i<(2*n - 2); i++) {
        string sub, rev; cin >> sub;
        reverse(all(sub));
        if(book.count(sub)) {
            book.erase(sub);
        } else {
            reverse(all(sub));
            book.insert(sub);
        }
    }
    if(book.empty()) puts("YES");
    else puts("NO");
}

int32_t main(){
    int t; cin >> t;
    while(t--) solve();
}
