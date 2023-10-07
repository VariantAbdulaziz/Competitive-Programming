#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve(){
    int m; cin >> m;
    vector<vector<int>> dict;
    for(int i=0; i<m; i++) {
        int n; cin >> n;
        vector<int> a;
        a.resize(n);
        for(auto &aj: a) {
            cin >> aj;
        }
        dict.push_back(a);
    }
    set<int> book;
    vector<int> result;
    reverse(all(dict));
    for(auto &a: dict) {
        int now = -1;
        for(auto aj: a) {
            if(!book.count(aj)) now = aj;
            book.insert(aj);
        }
        if(now == -1) {
            puts("-1");
            return;
        }
        result.push_back(now);
    }
    reverse(all(result));
    for(auto aj: result) cout << aj << " ";
    cout << endl;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
