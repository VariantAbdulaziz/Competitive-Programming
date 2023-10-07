#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll l, r, a;
        cin >> l >> r >> a;
        ll result = r / a + r % a;
        cout << result << '\n';
    }
}