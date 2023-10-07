#include <bits/stdc++.h>

using namespace std;

void solve(){
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        set<int> book;
        int c = 0;
        for(int i = n - 1; i >= 0; i--){
            if(book.count(a[i])) break;
            book.insert(a[i]);
            c++;
        }
        cout << n - c << '\n';
    }
}

int main(){
    solve();
}