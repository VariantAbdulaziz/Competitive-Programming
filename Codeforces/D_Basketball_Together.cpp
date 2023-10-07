#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    int n, d;
    cin >> n >> d;
    vector<int> p(n);
    for(auto& pj: p){
        cin >> pj;
    }
    int result = 0;
    sort(begin(p), end(p));
    for(int l=0, r=n-1; l <= r; r--){
        int sum = p[r];
        while(l < r && sum <= d){
            sum += p[r];
            l++;
        }
        if(sum > d) result++;
    }
    cout << result;
}

int32_t main(){
    solve();
}