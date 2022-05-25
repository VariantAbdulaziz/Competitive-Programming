// source: https://codeforces.com/problemset/problem/1/A

// strategy: an ad hoc solution
#include <cmath>
#include <iostream>
    
int main(){
    unsigned long long m, n, a, ans;
    std::cin >> m >> n >> a;
    ans = ceil((double)m/a) * ceil((double)n/a);
    std::cout << ans;
}