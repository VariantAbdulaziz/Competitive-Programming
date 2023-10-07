#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int helper(vector<int>& cache, string s, int idx, int width){
    // base case
    if(idx >= s.size()) return 0;

    // check if already processed
    auto &result = cache[idx];
    if(result != -1) return result;

    
    result = INT_MAX;
    for(int i=idx; i < s.size() && i - idx <= width; i++){
        if (i == s.size()-1 || s[i+1] == ' '){
            int B = width - (i - idx);
            result = min(result, B*B + helper(cache, s, i+2, width));
        }
    }
    return result;
}

int PrettyPrinting(string s, int width){
    
    vector<int> cache(s.size(), -1);
    return helper(cache, s, 0, width);
}


void solve(){
    string s;
    int width;
    getline(cin, s);
    cin >> width;

    int mininum_messiness = PrettyPrinting(s, width);
    cout << mininum_messiness;
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
}
