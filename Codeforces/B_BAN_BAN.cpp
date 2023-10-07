#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> swaps;
    for(int l=2, r=3*n; l < r; r-=3, l+=3){
        swaps.push_back({l, r});
    }
    cout << swaps.size() << endl;
    for(auto [l, r]: swaps){
        cout << l << " " << r << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}