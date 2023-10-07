#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dp(vector<vector<int>>& cache, vector<int>& connections, vector<int> &left, vector<int> &right, int l, int r){
    if(l >= r) return 0;

    auto &result = cache[l][r];
    if(result != -1) return result;

    result = INT_MAX;
    if(connections[l] == connections[r]){
        result = right[r] + left[l] + dp(cache, connections, left, right, l+1, r-1);
    }
    else{
        if(r+1 < connections.size())
            result = min(result, right[l] - right[r+1] + dp(cache, connections, left, right, l+1, r));
        else{
            dp(cache, connections, left, right, l+1, r);
            result = min(result, right[l] - right[r]);
        }


        if(l-1 >= 0)
            result = min(result, left[r] - left[l-1] + dp(cache, connections, left, right, l, r-1));
        else{
            dp(cache, connections,left, right, l, r-1);
            result = left[r] - left[l];
        }

    }
    
    return result;
}


void solve(){
    int n;
    cin >> n;
    vector<int> connections(n), left(n), right(n);
    for(auto &c: connections) cin >> c;

    for(int i=0; i<n; i++){

        if(i+1 < n && connections[i] != connections[i+1]){
            left[i+1] = left[i] + 1;
        } else if(i+1 < n) {
            left[i+1] = left[i];
        }
    }

    for(int i=n-1; i>=0; i--){
        if(i-1 >=0 && connections[i] != connections[i-1]){
            right[i-1] = right[i] + 1;
        } else if(i-1 >= 0) {
            right[i-1] = right[i];
        }
    }
    
    vector<vector<int>> cache(n, vector<int>(n, -1));
    dp(cache, connections, left, right, 0, n-1);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << cache[i][j] << " ";
        }
        cout << endl;
    }

}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
}
