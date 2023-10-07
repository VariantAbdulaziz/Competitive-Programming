#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int mid = n / 2, ans = 0;
    // cout << mid;
    deque<int> left, right;
    for(int i=0; i<n; i++){
        if(s[i] == 'L'){
            ans += i;
            if(i <= mid) {
                left.push_back(i);
            }
        }
        if(s[i] == 'R'){
            ans += n - i - 1;
            if(i >= mid) {
                right.push_back(i);
            }
        }
    }
    for(int k=0; k<n; k++){
        int i;
        int left_ans = ans, right_ans = ans;
        if(!left.empty()) {
            i = left.front();
            left_ans -= i;
            left_ans += n - i - 1;
        }
        if(!right.empty()){
            i = right.back();
            right_ans -= n - i - 1;
            right_ans += i;
        }
        if(left_ans > right_ans){
            if(!left.empty()) left.pop_front();
        } else {
            if(!right.empty()) right.pop_back();
        }
        ans = max(left_ans, right_ans);
        cout << ans << " ";
    }
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
