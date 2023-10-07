#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


void solve(int tc){
    int t; cin >> t;
    string path;
    long res = numeric_limits<long>::max();
    function<void(int,int)> dfs = [&](int start, int sum){
        if(sum==t) {
            res = min(res, stol(path));
        }
        if(sum>t) return;
        for(int i=start+1; i<10; i++){
            path.push_back(i + '0');
            dfs(i,sum+i);
            path.pop_back();
        }
    };
    for(int i=0; i<10; i++){
        dfs(i, 0);
    }
    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve(i);
}