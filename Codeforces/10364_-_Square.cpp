#include <iostream>
#include <vector>

void solve(){
    int sticks_count;
    std::cin >> sticks_count;
    std::vector<int> sticks(sticks_count);
    int squared_side = 0;

    for(int idx = 0; idx < sticks_count; idx++){
        std::cin >> sticks[idx];
        squared_side += sticks[idx];
    }
    
    
    if(squared_side % 4){
        std::cout << "no\n";
        return;
    }

    squared_side /= 4;
    std::vector<int> cache(1<<sticks_count, -1);
    auto dp = [&](auto&& dp, int mask, int side){
        if(side > squared_side)
            return 0;
        if(side == squared_side && mask == ((1 << sticks_count) - 1))
            return 1;
        
        auto& res = cache[mask];
        if(res != -1)
            return res;
        
        if(side == squared_side) side = 0;
        res = 0;
        for(int idx = 0; idx < sticks_count; idx++){
            if(mask & (1 << idx)) continue;

            res = res || dp(dp, mask | (1<<idx), side + sticks[idx]);
        }
        return res;
    };

    if(dp(dp, 0, 0))
        std::cout << "yes\n";
    else
        std::cout << "no\n";
}

int main(){
    int test_cases;
    std::cin >> test_cases;
    while(test_cases--){
        solve();
    }
}