#include <vector>
#include <iostream>

using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &aj: a)
        cin >> aj;

    for(int i = 0; i < a.size(); i++){
        for(int j = a.size() - 1; j > (i + 1); j--){
            if(a[i] == a[j]){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}