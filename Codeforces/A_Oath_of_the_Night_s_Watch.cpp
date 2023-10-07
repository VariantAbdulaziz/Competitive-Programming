#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    int hi = numeric_limits<int>::min();
    int lo = numeric_limits<int>::max();
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        hi = max(hi, temp);
        lo = min(lo, temp);
        a[i] = temp;
    }
    int c = 0;
    for(auto aj: a){
        if(aj != lo && aj != hi) c++;
    }
    cout << c;
}

int main(){
    solve();
}