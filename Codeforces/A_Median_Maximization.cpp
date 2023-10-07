#include <bits/stdc++.h>
#define int int64_t

using namespace std;

bool validMedian(int candidate, int array_size, int total){
    return total >= (candidate * (array_size / 2 + 1));
}

void solve(){
    int n, s;
    cin >> n >> s;

    int median = 0;
    for(int j = s/2 + 1; j > 0; j /= 2){
        while(validMedian(median + j, n, s)) median += j;
    }
    cout << median << endl;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}