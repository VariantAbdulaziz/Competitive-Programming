#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll n, t;
    cin >> n; cin >> t;
    vector<int> a(n);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int res = 0;
    ll tempt = 0;
    for(int r=0, l=0; r<n; r++){
        tempt += a[r];
        while(l < n && tempt>t) {
            tempt-=a[l++];
        }
        res = max(res, r - l + 1);
    }
    cout << res;
}