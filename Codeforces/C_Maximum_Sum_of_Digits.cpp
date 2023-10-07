#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

lli S(lli a){
    lli result = 0;
    string s = to_string(a);
    for(auto ch: s){
        result += (ch - '0');
    }
    return result;
}

int main(){
    string s;
    cin >> s;
    lli n = stoll(s);

    --s[0];
    for(int i=1; i<s.size(); i++){
        s[i] = '9';
    }
    lli a = stoll(s);
    lli b = n - a;
    cout << S(a) + S(b);
}