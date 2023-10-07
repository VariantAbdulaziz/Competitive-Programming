#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> statements(n);
    for(auto &s: statements){
        char temp; cin >> temp;
        s = (temp == 'f'? 1: 0);
    }
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){ // fix the state

            if(statements[i]){
                dp[i+1][j] += dp[i][j];
                for(int k=0; k < n; k++){
                    dp[k][j] += dp[i][j];
                }
            }

        }
    })
}