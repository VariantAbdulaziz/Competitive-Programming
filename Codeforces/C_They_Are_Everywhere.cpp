#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int len(int freq[]){
    int count = 0;
    for(int i=0; i<128; i++){
        if(freq[i]) count++;
    }
    return count;
}

void solve(int tc){
    int n; cin >> n;
    string s; cin >> s;
    int freq[128] = {0};
    int flats = 0, streak = 0;

    for(int l=0, r=0; r<n; r++){
        freq[s[r]]++;
        while(freq[s[l]] > 1)
            freq[s[l++]]--;
        
        if(len(freq) > streak)
            flats = r - l + 1;
        else if(len(freq) == streak)
            flats = min(r-l+1, flats);
        streak = max(streak, len(freq));
    }
    cout << flats;
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    for(int i=0; i<t; i++)
        solve(i);
}
