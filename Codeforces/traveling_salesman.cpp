#include <bits/stdc++.h>


using namespace std;

int main(){
    vector<vector<int>> cache, dist;
    auto dp = [&](auto&& dp, int mask, int last){
        if(mask == (1 << n) - 1) return dist[last][0];
        auto& res = cache[mask][last];
        if(res != INT_MAX) return res;

        for(int l=0; l<n; l++){
            if(mask != (1<<l)){
                new_mask = mask | (1<<l);
                res = min(res, dist[l][last] + dp(dp, new_mask, l));
            }
        }
    };
}