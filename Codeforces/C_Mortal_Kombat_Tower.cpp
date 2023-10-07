#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(auto& aj: a) cin >> aj;

        vector<vector<int>> cache(n + 1, {INT_MAX, INT_MAX});

        cache[0][1] = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<2; j++){
                if(cache[i][j] == INT_MAX) continue;
                if(i+1 <= n) {
                    cache[i+1][1-j] = min(cache[i+1][1-j], cache[i][j] + j * a[i]);
                }
                if(i+2 <= n) {
                    cache[i+2][1-j] = min(cache[i+2][1-j], cache[i][j] + j * (a[i] + a[i+1]));
                }
            }
        }

        cout << min(cache[n][0], cache[n][1]) << '\n';
    }
}