#include <bits/stdc++.h>

#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve(){
    string s;
    cin >> s;
    int uniques = 0;
    map<char, int> book;
    for(auto ch: s) {
        book[ch]++;
        if(book[ch] == 1) {
            uniques++;
        }
    }
    if(uniques == 1) {
        puts("-1");
    } else if(uniques == 3 || uniques == 4 || (*book.begin()).second == 2) {
        puts("4");
    } else {
        puts("6");
    }
}

int32_t main(){
    int t; cin >> t;
    while(t--) solve();
}
