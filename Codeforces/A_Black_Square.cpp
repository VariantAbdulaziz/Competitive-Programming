#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    vector<int> a(4);
    for(auto &aj: a) cin >> aj;

    string s; cin >> s;
    int ans = 0;
    for(auto sj: s){
        ans += a[sj - '1'];
    }
    cout << ans;
}