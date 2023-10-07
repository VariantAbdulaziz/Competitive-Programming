#include <bits/stdc++.h>
#define int int64_t

using namespace std;

bool valid(int candidate, int first, int second, int H){
    return ((candidate / 2 + (candidate % 2? 1: 0)) * first + (candidate / 2 * second)) < H;
}

void solve(){
    int n, h;
    cin >> n >> h;
    int first = 0, second = 0;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(temp > first){
            swap(first, second);
            first = temp;
        } else if(temp > second){
            second = temp;
        }
    }

    int station = 0;
    for(int j = h/2; j > 0; j /= 2){
        while(valid(station + j, first, second, h))
            station += j;
    }
    cout << station + 1 << '\n';
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}