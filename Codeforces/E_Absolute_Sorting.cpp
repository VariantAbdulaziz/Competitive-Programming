#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& aj: A){
        cin >> aj;
    }
    if(is_sorted(begin(A), end(A))){
        cout << 0;
    } else if(is_sorted(rbegin(A), rend(A))){
        cout << *max_element(A.begin(), A.end());
    } else {
        int x = ceil((*max_element(A.begin(), A.end()) + *min_element(A.begin(), A.end())) / 2.0);
        int prev = 0;
        bool first = true;
        for(auto &aj: A){
            aj = abs(aj - x);
            if(first && aj < prev){
                first = false;
            }
            prev = aj;
        }
        if(first) cout << x;
        else {
            int x = (*max_element(A.begin(), A.end()) + *min_element(A.begin(), A.end())) / 2;
            int prev = 0;
            for(auto &aj: A){
                aj = abs(aj - x);
                if(aj < prev){
                    cout << -1;
                    return;
                }
                prev = aj;
            }
            cout << x;
        }
    }
}


int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}