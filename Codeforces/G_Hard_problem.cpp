#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

lli dp(vector<vector<lli>>& cache, vector<int>& cost, vector<string>& dict, int i, int turn){
    if(i >= dict.size()) return 0;

    auto& result = cache[i][turn];
    if(result != -1) return result;

    result = LLONG_MAX;
    
    string compared;
    if(turn) compared = string(dict[i].rbegin(), dict[i].rend());
    else compared = dict[i];

    lli temp = dp(cache, cost, dict, i+1, 0);
    if(temp != LLONG_MAX && (i+1 == dict.size() || compared <= dict[i+1]))
        result = min(result, (turn? cost[i]: 0) + temp);
    
    temp = dp(cache, cost, dict, i+1, 1);
    if(temp != LLONG_MAX && (i+1 == dict.size() || compared <= string(dict[i+1].rbegin(), dict[i+1].rend())))
        result = min(result, (turn? cost[i]: 0) + temp);
    
    return result;
}

int main(){
    int n; cin >> n;
    vector<int> cost(n);

    for(auto& c: cost) cin >> c;
    vector<string> dict(n);
    for(int i=0; i<n; i++){
        cin >> dict[i];
    }
    
    vector<vector<lli>> cache(n, vector<lli>(2, -1));
    lli result = min(dp(cache, cost, dict, 0, 0), dp(cache, cost, dict, 0, 1));
    cout << (result == LLONG_MAX? -1: result);
}