#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), count;
    priority_queue<pair<int, int>> q;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        if(a[i] > 0)
            q.push({a[i], i});
    }
    vector<pair<int, int>> meetings;
    
    while(q.size() > 1){
        auto [ax, x] = q.top(); q.pop();
        auto [ay, y] = q.top(); q.pop();
        meetings.push_back({x, y});
        ax--; ay--;
        if(ax) q.push({ax, x});
        if(ay) q.push({ay, y});
    }
    cout << meetings.size() << endl;
    for(auto [x, y]: meetings) {
        cout << x + 1 << " " << y + 1 << endl;
    }
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
