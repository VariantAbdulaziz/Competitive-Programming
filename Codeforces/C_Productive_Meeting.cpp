#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    vector<pair<int, int>> talks;
    while(t--){
        int n;
        cin >> n;
        priority_queue<pair<int, int>> q;

        for(int i=0; i<n; i++){
            int sociability;
            cin >> sociability;
            if(sociability) q.push({sociability, i+1});
        }
        talks.clear();
        while(q.size() > 1){
            auto [si, i] = q.top(); q.pop();
            auto [sj, j] = q.top(); q.pop();
            talks.push_back({i, j});
            si--; sj--;
            if(si) q.push({si, i});
            if(sj) q.push({sj, j});
        }
        cout << talks.size() << '\n';
        for(auto [i, j]: talks){
            printf("%d %d\n", i, j);
        }
    }
}