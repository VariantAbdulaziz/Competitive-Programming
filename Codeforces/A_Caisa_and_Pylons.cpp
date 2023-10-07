#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int pylons;
    cin >> pylons;
    int energy = 0, money = 0, prior_kth = 0;
    for(int k=1; k<=pylons; k++){
        int pylon;
        cin >> pylon;
        energy += prior_kth - pylon;
        if(energy < 0) {
            money += abs(energy);
            energy = 0;
        }
        prior_kth = pylon;
    }
    cout << money;
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    solve();
}
