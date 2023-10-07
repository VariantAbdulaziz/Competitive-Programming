#include <bits/stdc++.h>

using namespace std;

int a[200001];

void solve(){
    int tc; cin >> tc;
    while(tc--){
        int n, s; cin >> n >> s;
        
        a[0] = 0;
        for(int i=1; i<n+1; i++){
            int temp; cin >> temp;
            a[i] = a[i-1] + temp;
        }
        int res = -1;
        for(int r=1, l=0; r <= n; l++){
            while (r <= n && a[r] - a[l] <= s){
                if(a[r] - a[l] == s) {
                    res = max(res, r - l);
                }
                r++;
            }
        }
        cout << (res == -1? res: n - res) << '\n';
    }
}

int main(){
    solve();
}