#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

tuple<ll, int, int> max_subarray(vector<ll>& nums){
    ll _cur = 0, _result = LLONG_MIN;
    int left = 0, right = 0, _cur_left = 0;

    for(int i=0; i<nums.size(); i++){
        // printf("%d:%d:%d\n", left, right, _cur_left);
        if(nums[i] >= _cur + nums[i]){
            _cur = nums[i];
            _cur_left = i;
        } else {
            _cur = _cur + nums[i];
        }

        if(_cur > _result){
            _result = _cur;
            left = _cur_left;
            right = i;
        }
    }
    return {_result, left, right};
}

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    ll _sum = 0;
    for(auto aj: a) _sum += aj;
    auto [adel_tastiness_consumption, l, r] = max_subarray(a);

    // printf("%d:%d %lld:%lld ", l, r, adel_tastiness_consumption, _sum);
    if((r - l + 1 != a.size()) && _sum <= adel_tastiness_consumption){
        printf("NO\n");
    }
    else printf("YES\n");
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
        solve();
}
