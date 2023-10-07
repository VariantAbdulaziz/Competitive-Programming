#include <bits/stdc++.h>


using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &aj: a) cin >> aj;

        int have = 0;
        for(int j=0; j<n; j++){
            int largest = 0;
            for(int i=1; !((a[j])%(1<<i)); i++){
                largest = i;
            }
            have += largest;
        }

        if(have >= n) {
            cout << 0 << '\n';
            continue;
        }
        priority_queue<int> q;
        for(int i=2; i<=n; i+=2){
            int largest = 0;
            while(!(i % (1<<largest))){
                largest++;
            }
            q.push(largest-1);
        }

        int operations = 0;
        bool found = false;
        while(!q.empty()){
            auto cur = q.top(); q.pop();
            have += cur;
            operations++;
            if(have >= n){
                cout << operations << '\n';
                found = true;
                break;
            }
        }
        if(!found) cout << -1 << '\n';
    }
}