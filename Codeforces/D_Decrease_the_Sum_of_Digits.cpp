#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll sumDigits(string s){
    ll result = 0;
    for(auto c: s){
        result += c - '0';
    }
    return result;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s, orig;
        ll q;

        cin >> s >> q;
        orig = s;
        ll total = sumDigits(s);
        int lsd = s.size() - 1;
        
        bool start = true;
        while((lsd >= 0) and (total > q)){
            if(!start) s[lsd]++;
            total++;
            total -= (s[lsd] - '0');
            s[lsd] = '0';
            start = false;
            lsd--;
        }

        if(s != orig){
            while(lsd >= 0 && s[lsd] == '9'){
                s[lsd] = '0';
                lsd--;
            }
            if(lsd >= 0)
                s[lsd]++;
        }
        
        if(s[0] == '0'){
            s.insert(s.begin(), 1, '1');
        }
        
        cout << stoull(s) - stoull(orig) << '\n';
    }
}