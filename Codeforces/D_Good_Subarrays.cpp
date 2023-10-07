#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> prefix(n+1);
    int result = 0;
    deque<int> dq;
    dq.push_back(0);
    for(int i=1; i<=n; i++){
        prefix[i] = prefix[i-1] + (s[i-1] - '0');
        for(int i=dq.size() - 1; i>=0; i++){
            if((prefix[i] - prefix[dq.front()]) == (i - dq[i] + 1))
                result++;
        }
        while(!dq.empty() && (prefix[i+1] - prefix[dq.front()]) == (i - dq.front() + 1)){
            dq.pop_front();
        }
        dq.push_back(i);
    }

    cout << result;
    
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}