//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
int total_cost(vector<vector<int>>cost){
    
    int n = cost.size();
    vector<vector<int>> cache(1 << n, vector<int>(n, INT_MAX));
    
    auto dp = [&](auto&& dp, int mask, int last){
        if(mask == (1 << n) - 1) return cost[last][0];
        
        auto& res = cache[mask][last];
        if(res != INT_MAX) return res;

        for(int l=0; l<n; l++){
            if(mask & (1<<l)) continue;
            int new_mask = mask | (1<<l);
            res = min(res, cost[last][l] + dp(dp, new_mask, l));
        }
        return res;
    };
    
    int res = INT_MAX;
    for(int i=1; i<n; i++){
        res = min(res, cost[0][i] + dp(dp, ((1<<0)|1<<i), i));
    }
    return res == INT_MAX? 0: res;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends