#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t = 0;

void solve(int n){
    vector<tuple<string, int, int>> info(2*n);
    for(int i=0; i<2*n; i++){
        string name;
        int x, y;
        cin >> name >> x >> y;
        info[i] = {name, x, y};
    }

    auto dist = [](tuple<string, int, int> p, tuple<string, int, int> q){
        return sqrt(pow(get<1>(p) - get<1>(q), 2) + pow(get<2>(p) - get<2>(q), 2));
    };

    vector<double> cache(1<<(2*n), INT_MAX);

    auto dp = [&](auto&& dp, int mask){
        if(mask == (1 << (2*n)) - 1) return 0.0;

        auto& pair_distance_summations = cache[mask];
        if(pair_distance_summations != INT_MAX) return pair_distance_summations;
        

        for(int i=0; i<(2*n); i++){
            if(mask & (1<<i)) continue;
            int new_mask = mask | (1<<i);
            for(int j=0; j<(2*n); j++){
                if(new_mask & (1<<j)) continue;
                pair_distance_summations = min(pair_distance_summations, dist(info[i], info[j]) + dp(dp, new_mask | (1<<j)));
            }
        }
        return pair_distance_summations;
    };

    printf("Case %d: %.2f\n", ++t, dp(dp, 0));
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t; cin >> t;
    while(t){
        solve(t);
        cin >> t;
    }
}
