#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<int>& vec, long long start, int end){
    if(start > end) return false;
    if(start == end){
        vec.push_back(start);
        return true;
    }
    if(dfs(vec, 10*(start)+1, end)){
        vec.push_back(start);
        return true;
    }
    if(dfs(vec, 2*start, end)){
        vec.push_back(start);
        return true;
    }
    return false;
}

void solve(){
    int start, end;
    vector<int> vec;
    cin >> start >> end;
    if(dfs(vec, start, end)){
        int n = vec.size()-1;
        cout << "YES\n" << n+1 << "\n";
        cout << start << " ";
        while(n--){
            cout << vec[n] << " ";
        }
    } else cout << "NO\n";
}
int main(){
    solve();
}