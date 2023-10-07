#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    int N, result;
    cin >> N;
    vector<int> A(N);
    for(auto &aj: A){
        cin >> aj;
    }
    for(int l=0, r=0; r<N; r++){
        if(r > 0 && A[r-1] > A[r]){
            l = r;
        }
        result = max(result, r - l + 1);
    }
    cout << result;
}

int32_t main(){
    solve();
}