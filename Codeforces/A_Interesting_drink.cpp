#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){

}

int32_t main(){
    int n, q;
    cin >> n;
    vector<int> x(n);
    for(auto &xi: x){
        cin >> xi;
    }
    sort(begin(x), end(x));
    cin >> q;
    // 3 6 8 10 11
    while(q--){
        int query;
        cin >> query;
        auto found = upper_bound(begin(x), end(x), query) - begin(x);
        cout << found << endl;
    }
}