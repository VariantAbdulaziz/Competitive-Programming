#include <bits/stdc++.h>
#define int int64_t

using namespace std;

const int INF = 2e18;

int32_t main(){
    int no_of_pieces;
    cin >> no_of_pieces;

    vector<int> pie(no_of_pieces);
    for(int i=0; i <= no_of_pieces; i++){
        cin >> pie[i];
    }

    for(int i=0; i<=no_of_pieces; i++){
        for(int j=0; j<2; j++){ // fix the state

            for(int k=i+1; k<=no_of_pieces; k++){
                dp[k][1-j] = j?
                            max(dp[k][1-j], dp[i][j]):
                            min(dp[k][1-j], dp[i][j]);
            }
        }
    }


}