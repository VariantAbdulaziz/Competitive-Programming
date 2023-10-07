#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    string A, result;
    cin >> A;
    for(int l=0, r=A.size()-1; l<=r; l++){
        result.push_back(A[l]);
        if(A[l] == A[r]) {
            r--;
        }
    }
    cout << result + (string{result.rbegin(), result.rend()}) << endl;
}

int32_t main(){
    solve();
}