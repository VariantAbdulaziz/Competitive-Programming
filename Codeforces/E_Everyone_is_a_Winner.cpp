#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> result;
    int count = n + 1;
    set<int> book;
    while(count > 0) {
        book.insert(n / count);
        if(!book.count(n / (count - 1))) {
            count--;
        } else count /= 2;
    }
    cout << book.size();
    bool first = true;
    for(auto r: book) {
        if(first) cout << endl;
        first = first && false;
        cout << r << " ";
    }
}

int32_t main() {
    int t; cin >> t;
    while(t--) {
        solve();
        cout << endl;
    }
}
