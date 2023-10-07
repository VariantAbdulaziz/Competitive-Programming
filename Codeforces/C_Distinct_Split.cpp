#include <bits/stdc++.h>
#define int int64_t

using namespace std;

int sum(vector<int>& freq){
    int result = 0;
    for(auto &f: freq) {
        if(f) result += 1;
    }
    return result;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> freq(26);
    vector<vector<int>> after, before;
    after.resize(n);
    before.resize(n);
    
    for(int i=n-1; i>=0; i--) {
        after[i] = freq;
        freq[s[i] - 'a']++;
    }
    freq = vector<int>(26);
    int result = 0;
    for(int i=0; i<n; i++){
        freq[s[i] - 'a']++;
        before[i] = freq;
        result = max(result, sum(before[i]) + sum(after[i]));
    }
    cout << result;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
