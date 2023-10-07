            #include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int a = 0, b = 0, result = 0;
    for(int r=0, l=0; r < s.size(); r++){
        if(s[r] == 'a') a++;
        else b++;
        while(min(a, b) > k && l < s.size()){
            if(s[l++] == 'a') a--;
            else b--;
        }
        result = max(result, r - l+1);
    }
    cout << result;

}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
}
