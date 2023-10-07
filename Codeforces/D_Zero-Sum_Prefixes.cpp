#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    int result = 0;
    int run = 0;
    for(int i=0; i<n; i++){
        int ai;
        cin >> ai;
        if(!ai){
            ai = -run;
        }
        run += ai;
        if(!run) result++;
    }
    cout << result;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}