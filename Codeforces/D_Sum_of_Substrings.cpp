#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    deque<int> q;
    int ans = 0;
    for(int seeker; seeker<n;){
        if(s[seeker] == '1') {
            q.push_back(seeker);
        } 
        while (!q.empty() && s[seeker] < s[q.back()]) {
                if(seeker - q.back() < k) {
                    swap(s[seeker], s[q.back()]);
                    k -= seeker - q.back();
                    seeker = q.back();
                }
                q.pop_back();
            }
    }
    for(int l=0, r=1; r<n; l++, r++){
        ans += stoi(s.substr(l, 2));
    }
    cout << ans;
}

int32_t main(){
    int t; cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
