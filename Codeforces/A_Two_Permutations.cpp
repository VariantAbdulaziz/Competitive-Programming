#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    if(a + b + 1 < n || (a == n && b == n)){
        cout << "Yes";
    } else {
        cout << "No";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}