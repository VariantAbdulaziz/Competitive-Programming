#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int n, result = 0;
    cin >> n;
    vector<int> a(n);
    for(auto &aj: a) cin >> aj;

    int _min = *min_element(a.begin(), a.end());
    for(auto aj: a) result += (aj - _min);
    cout << result << endl;
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
        solve();
}
