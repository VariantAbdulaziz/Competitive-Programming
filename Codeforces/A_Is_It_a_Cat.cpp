#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    string meow = "meow";
    int i=0;
    for(auto ch: s) {
        if(tolower(ch) == meow[i]);
        else if(i + 1 < 4 && tolower(ch) == meow[i + 1]) {
            i++;
        } else {
            puts("NO");
            return;
        }
    }
    if(i >= 3)
        puts("YES");
    else puts("NO");
}

int32_t main(){
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
}
