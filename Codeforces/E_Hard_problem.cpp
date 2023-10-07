#include <bits/stdc++.h>
#define int int64_t

using namespace std;

const int inf = 4e18;

int32_t main(){
    int n;
    cin >> n;
    vector<int> cost(n);
    vector<string> dict(n);
    for(auto &c: cost) cin >> c;
    for(auto &word: dict){
        cin >> word;
    }
    vector<vector<int>> cache(n + 1, vector<int>(2, inf));
    cache[0][0] = 0;
    cache[0][1] = 0;
    for(int i=0; i<n; i++){
        for(int is_reversed=0; is_reversed<2; is_reversed++){ // fix the state
            int added_value = is_reversed? cost[i]: 0;
            string curr = dict[i];
            string next = ((i+1) < dict.size())? dict[i+1]: "";

            if(is_reversed) reverse(begin(curr), end(curr));
            if(curr <= next || (i+1 == dict.size()))
                cache[i+1][0] = min(cache[i+1][0], added_value + cache[i][is_reversed]);
            reverse(begin(next), end(next));
            if(curr <= next || (i+1 == dict.size()))
                cache[i+1][1] = min(cache[i+1][1], added_value + cache[i][is_reversed]);
        }
    }
    int result = min(cache[n][0], cache[n][1]);
    cout <<(result >= inf? -1: result) << endl;
}