#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool check(vector<int>& in_pool, int i){
    string s = to_string(i);
    vector<int> count(10);
    count[0] += (4 - s.size());
    if(count[0] && !in_pool[0]) return false;
    for(auto& ch: s) {
        if(!in_pool[ch - '0']) return false;
        count[ch - '0']++;
    }
    int digits = 0;
    for(auto& c: count){
        if(c != 0 && c != 2) return false;
        if(c != 0) digits++;
    }
    return digits == 2;
}

void solve(){
    int n;
    cin >> n;
    vector<int> in_pool(10, 1);

    for(int i=0; i<n; i++){
        int aj; cin >> aj;
        in_pool[aj]--;
    }
    int passwords = 0;
    for(int i=11; i<10000; i++){

        if(check(in_pool, i)) {
            passwords++;
        }
    }
    printf("%d\n", passwords);
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    while(t--)
        solve();
}
