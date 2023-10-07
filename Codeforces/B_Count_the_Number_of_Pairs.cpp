#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> lowers(26), uppers(26);
    for(auto ch: s) {
        if(islower(ch)) {
            lowers[ch - 'a']++;
        } else {
            uppers[ch - 'A']++;
        }
    }
    int ans = 0;
    for(int i=0; i<26; i++) {
        if(k) {
            int _max = max(lowers[i], uppers[i]);
            int _min = min(lowers[i], uppers[i]);
            int op =  min((_max - _min) / 2, k);

            if(uppers[i] == _max) uppers[i] -= op;
            else uppers[i] += op;
            if(lowers[i] == _max) lowers[i] -= op;
            else lowers[i] += op;
            k -= op;
        }
        ans += min(lowers[i], uppers[i]);
    }
    cout << ans << endl;
}

int32_t main(){
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
