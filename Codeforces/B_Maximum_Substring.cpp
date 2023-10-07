#include <bits/stdc++.h>
#define int int64_t

using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ones = 0, zeros = 0;
        for(auto ch: s){
            ones += (ch == '1'? 1: 0);
            zeros += (ch == '0'? 1: 0);
        }
        int longest_ones = 0, longest_zeros = 0;

        for(int r=0; r<n; r++){
            int l = r;
            while(s[r] == '1'){
                longest_ones = max(longest_ones, r - l + 1);
                r++;
            }
        }
        for(int r=0; r<n; r++){
            int l = r;
            while(s[r] == '0'){
                longest_zeros = max(longest_zeros, r - l + 1);
                r++;
            }
        }
        cout << max(ones * zeros, max(longest_ones*longest_ones, longest_zeros*longest_zeros)) << endl;
    }
}