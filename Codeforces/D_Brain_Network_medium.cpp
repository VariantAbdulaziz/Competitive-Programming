#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> book(n);
    for(int i=0; i<m; i++){
        vector<int> connection(2);
        cin >> connection[0] >> connection[1];
        book[--connection[0]]++;
        book[--connection[1]]++;
        adj[connection[0]].push_back(connection[1]);
        adj[connection[1]].push_back(connection[0]);
    }
}