#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &aj: a){
        cin >> aj;
    }
    int count = 0;
    for(int l=0; l < a.size();){
        int r = l;
        while(r + 1 < a.size() && a[r + 1] == a[l]){
            r++;
        }
        if((l == 0 || a[l-1] > a[l]) &&
            (r+1 == a.size() || a[r+1] > a[r])){
                count++;
            }
        l = r + 1;
    }
    if(count == 1){
        cout << "YES";
    } else cout << "NO";
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}