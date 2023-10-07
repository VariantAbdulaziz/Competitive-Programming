#include <bits/stdc++.h>
#define int int64_t

using namespace std;
const int mod = 1e9 + 7;

int32_t main(){

    string s;
    cin >> s;
    vector<int> a, b;
    for(int i=0; i<s.size(); i++){

        if(s[i] == 'a')
            a.push_back(i+1);
        else if(s[i] == 'b')
            b.push_back(i+1);
    }
    vector<int> dp(a.size(), 1);
    for(int i=0; i<a.size(); i++){

        auto itr = upper_bound(begin(b), end(b), a[i]);
        for(int j=i+1; itr != end(b) && j<a.size(); j++){
            if((*itr) < a[j]){
                dp[j] += dp[i];
                dp[j] %= mod;
            }
        }
    }
    int result = 0;
    for(auto d: dp){
        result += d;
        result %= mod;
    }

    cout << result << endl;
}