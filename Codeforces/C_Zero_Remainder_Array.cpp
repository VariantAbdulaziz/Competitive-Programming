#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        map<int, int> mods;
        for(int i=0; i<n; i++){
            int val;
            cin >> val;
            mods[val % k]++;
        }
        ll result = 0;
        for(auto [mod, count]: mods){
            if(mod) result = max(result, (ll)(count-1)*k + k-mod + 1);
        }
        cout << result << '\n';
    }
}