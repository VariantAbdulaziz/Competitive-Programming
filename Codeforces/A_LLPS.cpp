#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, result;
    cin >> s;

    sort(begin(s), end(s));
    char c = s[s.size() - 1];
    for(auto ch: s){
        if(ch == c) result += ch;
    }
    cout << result;
}