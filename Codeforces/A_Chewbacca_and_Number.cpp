#include <bits/stdc++.h>

using namespace std;

void solve(){
    string x;
    cin >> x;
    for(int i=0; i<x.size(); i++) {
        if(x[i] < '5') continue;
        x[i] = '9' - x[i] + '0';
    }
    if(x[0] == '9') x[0] = '9';
    cout << x;
}

int main(){
    solve();
}