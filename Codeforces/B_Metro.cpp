#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, s;
    cin >> n >> s;
    vector<int> track_1(n + 1);
    vector<int> track_2(n + 1);
    for(int i=1; i<=n; i++){
        cin >> track_1[i];
    }
    for(int i=1; i<=n; i++){
        cin >> track_2[i];
    }

    if(track_1[1] && track_1[s]){
        cout << "YES\n";
        return 0;
    }
    else if(!track_1[1] || !track_2[s]){
        cout << "NO\n";
        return 0;
    }
    for(int i=s; i<=n; i++){
        if(track_1[i] && track_2[i]){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}