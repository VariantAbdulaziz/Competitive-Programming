#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(int tc){
    string s; cin >> s;
    if(s.size() % 2 != 0) cout << "NO";
    else{
        bool flag = true;
        for(int l=0, r=s.size() / 2; r < s.size(); l++, r++){
            if(s[l] != s[r]){
                flag = false;
                break;
            }
        }
        if(flag) cout << "YES";
        else cout << "NO";
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve(i);
}