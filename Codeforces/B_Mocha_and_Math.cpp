#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int _min;
        cin >> _min;
        for(int j=0; j<n-1; j++) {
            int a;
            cin >> a;
            _min &= a;
        }
        
        cout << _min << '\n';
    }
}