#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> boys(n);
    for(auto &b: boys){
        cin >> b;
    }
    int m;
    cin >> m;
    vector<int> girls(m);
    for(auto &g: girls){
        cin >> g;
    }
    int ans = 0, ans2 = 0;
    sort(begin(boys), end(boys));
    sort(begin(girls), end(girls));
    // 1 2 4 6
    // 1 5 5 7 9
    for(int l=0, r=0; l < n || r < m;){
        if(abs(boys[l] - girls[r]) < 2){
            l++, r++, ans++;
        } else if(boys[l] < girls[r]) {
            l++;
        } else{
            r++;
        }
    }
    
    for(int l=0, r=0; l >= 0 || r >= 0;){
        if(abs(boys[l] - girls[r]) < 2){
            l--, r--, ans2++;
        } else if(boys[l] < girls[r]) {
            l--;
        } else{
            r--;
        }
    }
    cout << max(ans, ans2);
}

int32_t main(){
    solve();
}