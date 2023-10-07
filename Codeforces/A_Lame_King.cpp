#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    map<pair<int, int>, int> book, visited;
    priority_queue<array<int, 4>, vector<array<int, 4>>, greater<>> q;
    vector<array<int, 3>> dirs = {{1, 0, 1}, {0, 1, 2}, {-1, 0, 3}, {0, -1, 4}};
    q.push({0, 0, 0, 0});
    while(!q.empty()) {
        auto [w, x, y, prev] = q.top(); q.pop();
        book[make_pair(x, y)] = min(book[make_pair(x, y)], w);

        if(x == a && y == b){
            cout << w << endl;
            return;
        }
        if(prev) q.push({w + 1, x, y, 0});
        for(auto [dx, dy, label]: dirs) {
            if(label != prev && x + dx < 101 && x + dx > -101 && y + dy < 101 && y + dy > -101 && (visited.find(make_pair(x + dx, y + dy)) == visited.end() || visited[make_pair(x + dx, y + dy)] - 1 != w)){
                q.push({w + 1, x + dx, y + dy, label});
                visited[make_pair(x + dx, y + dy)] = w + 1;
            }
        }
    }
}

int32_t main(){
    int t;
    cin >> t;
    while(t--) solve();
}
