#include <bits/stdc++.h>

using namespace std;

void solve(){
    int pebbles = 0;
    string s;
    cin >> s;
    for(int i=0; i<12; i++){
        
        if(s[i] == 'o')
            pebbles |= (1<<i);
    }

    auto dp = [&](auto&& dp, int mask){

    };
}

int main(){
    int n;
    cin >> n;
    while(n--){
        solve();
    }
}