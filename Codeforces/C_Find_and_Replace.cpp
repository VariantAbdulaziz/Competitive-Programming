#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> freq(26, -1);
    int bit = 0;
    for(auto sj: s) {
        if(freq[sj - 'a'] == -1){
            freq[sj - 'a'] = bit;
        } else if(freq[sj - 'a'] != bit){
            puts("NO");
            return;
        }
        bit = 1 - bit;
    }
    puts("YES");
}

int32_t main(){
    int t;
    cin >> t;
    while(t--) solve();
}