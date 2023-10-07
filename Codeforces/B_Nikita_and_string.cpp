#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> cache(n + 1, vector<int>(3));
    
    for(int i=0; i<n; i++){ // fix the state

        // transitions from it <> fix the state
        cache[i+1][0] = cache[i][0] + (s[i] == 'a'? 1: 0);
        cache[i+1][1] = (s[i] == 'b'? 1: 0) + max(cache[i][1], cache[i][0]);
        cache[i+1][2] = (s[i] == 'a'? 1: 0) + max(cache[i][1], cache[i][2]);
    }
    cout << max(cache[n][0], max(cache[n][1], cache[n][2])) << '\n';
}