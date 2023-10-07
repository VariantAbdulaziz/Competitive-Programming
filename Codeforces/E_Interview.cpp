#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve(){
    int n, i = 1; cin >> n;
    vector<int> a(n), book(n + 1);
    for(auto &aj: a) {
        cin >> aj;
        book[i] = aj + book[i - 1];
    }

    int l = 1, r = n;
    while(l < r) {
        int mid = (l + r) / 2;
        int expected= book[mid] - book[l - 1];
        int real;
        cout << "? " << mid - l + 1; 
        for(int i=l; i<=mid; i++) {
            cout << " " << i;
        }
        cout << endl;
        cin >> real;
        cout << endl;
        if(real == expected) {
            l = mid + 1;
        } else r = mid;
    }
    cout << "! " << l << endl; 
}

int32_t main(){
    int t; cin >> t;
    while(t--) solve();
}
