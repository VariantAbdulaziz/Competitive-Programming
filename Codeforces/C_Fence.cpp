#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> planks(n);
    for(auto &plank: planks) cin >> plank;

    int window = 0;
    for(int i=0; i<k; i++){
        window += planks[i];
    }

    int result = 0;
    int _min = window;
    for(int i=k; i<n; i++){
        window -= planks[i-k];
        window += planks[i];

        if(window < _min){
            result = i-k+1;
            _min = window;
        }
    }
    cout << result + 1;

}

int32_t main(){
    
    solve();
}
