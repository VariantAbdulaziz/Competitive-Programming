#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> rank(n + 1, 1);
    vector<int> link(n + 1);
    for(int i=0; i<=n; i++){
        link[i] = i;
    }
    auto find = [&](auto&& find, int node) -> int {
        if(node != link[node])
            link[node] = find(find, link[node]);
        return link[node];
    };
    auto cluster = [&](int ni, int nj){
        int ri = find(find, ni), rj = find(find, nj);
        if(ri == rj)
            return;
        if(rank[ri] < rank[rj])
            swap(ri, rj);
        rank[ri] += rank[rj];
        link[rj] = ri;
    };
    for(int i=0; i<m; i++){
        int ki; cin >> ki;
        vector<int> friends(ki);
        for(auto &f: friends) cin >> f;

        for(int j=1; j<ki; j++){
            cluster(friends[0], friends[j]);
        }
    }
    for(int i=1; i<=n; i++){
        cout << rank[find(find, i)] << " ";
    }
    cout << endl;
}