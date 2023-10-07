#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> aux(n);
        for(auto &aj: aux) cin >> aj;

        sort(begin(aux), end(aux));
        bool possible = true;
        for(int i=0, j=1; j < n; j++, i++){
            if((aux[j] - aux[i]) > 1) {
                possible = false;
                break;
            }
        }
        if(possible) puts("YES");
        else puts("NO");
    }
}