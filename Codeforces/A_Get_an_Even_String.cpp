#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s; cin >> s;
    int n = s.size();
    vector<int> dp(n + 1);
    vector<int> book(26, 0);
    for(int i=1; i<n; i++){
        dp[i] = dp[i-1];
        if (s[i] == s[book[s[i] - 'a']]) {
            dp[i] = max(dp[i], dp[max(book[s[i] - 'a'] - 1, 0)] + 2);
        }
        if (dp[max(i-1, 0)] >= dp[max(book[s[i] - 'a'] - 1, 0)]) {
            book[s[i] - 'a'] = i;
        }
        // for(int j=i-1; j>=0; j--){
        //     if(s[i] == s[j]){
        //         dp[i] = max(dp[i], dp[max(j-1, 0)] + 2);
        //     }
        // }
    }
    int result = *max_element(begin(dp), end(dp));
    cout << n - result;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}