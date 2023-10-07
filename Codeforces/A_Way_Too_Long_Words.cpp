#include <string>
#include <iostream>

using namespace std;

void solve(){
    string s;
    cin >> s;
    if(s.size() > 10){
        cout << s.front() << s.size() - 2 << s.back();
    } else {
        cout << s;
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}