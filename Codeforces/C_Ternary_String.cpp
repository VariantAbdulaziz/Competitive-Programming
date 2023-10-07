#include <bits/stdc++.h>

using namespace std;

bool valid(int freq[]){
    for(int i=0; i<3; i++){
        if(!freq[i]) return false;
    }
    return true;
}

void solve(){
    string s;
    cin >> s;
    int freq[3] = {0};
    int result = s.size() + 1;
    for(int l=0, r=0; r<s.size(); r++){
        freq[s[r] - '1']++;
        while(valid(freq)){
            result = min(result, r - l + 1);
            freq[s[l] - '1']--;
            l++;
        }
    }
    cout << result % (s.size() + 1);
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}