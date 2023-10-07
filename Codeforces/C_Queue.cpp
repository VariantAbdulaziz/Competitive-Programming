#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> result(n);
    map<int, int> forward, backward, visited;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        if(!a) {
            result[1] = b;
        }
        if(!b) {
            result[n-2] = a;
        }
        forward[a] = b;
        backward[b] = a;
        visited[a]++;
        visited[b]--;
    }
    for(auto [a, count]: visited){
        if(count == 1){
            result[0] = a;
        }
        if(count == -1){
            result[n-1] = a;
        }
    }
    
    for(int i=0; i<n; i++){
        if(result[i] && i+2<n){
            result[i+2] = forward.at(result[i]);
        }
    }
    for(int i=n-1; i>=0; i--){
        if(result[i] && i-2>=0){
            result[i-2] = backward.at(result[i]);
        }
    }

    for(int i=0; i<n; i++){
        if(i) cout << " ";
        cout << result[i];
    }
}