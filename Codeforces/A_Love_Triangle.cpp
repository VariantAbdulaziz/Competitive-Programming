#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<int>& visited, vector<int>& vec, int node, int pa, int gpa){
    if(visited[node]) return false;
    visited[node] = 1;
    if(vec[node] == gpa) return true;
    return dfs(visited, vec, vec[node], node, pa);
}

void solve(){
    int x;
    cin >> x;
    vector<int> vec(x+1), visited(x+1);

    for(int i=1; i<vec.size(); i++){
        cin >> vec[i];
    }
    bool flag = false;
    for(int i=1; i<vec.size(); i++){
        if (!visited[i] && dfs(visited, vec, i, -1, -1)){
            flag = true;
            break;
        }
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    solve();
}