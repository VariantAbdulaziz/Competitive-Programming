#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<int>& a, int start, int terminal){
    if(start == terminal) return true;
    if(start > terminal) return false;

    return dfs(a, a[start], terminal);
}

void solve(){
    int n, t;
    cin >> n >> t;
    vector<int> a(n+1);

    for(int i=1; i<n; i++){
        cin >> a[i];
        a[i] += i;
    }
    if(dfs(a, 1, t))
        printf("YES");
    else printf("NO");
}

int main(){
    solve();
}