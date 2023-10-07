#include <bits/stdc++.h>
#define int int64_t

using namespace std;

int32_t main(){
    int k; cin >> k;

    string s; cin >> s;
    int ones = 0, result = 0;
    if(!k){
        for(auto sj: s) result += 1-(sj - '0');
        cout << result;
        return 0;
    }
    for(int r=0, l=0; r<s.size();){
        ones += s[r] - '0'; r++;
        while(ones > k && l <= r){
            ones -= s[l] - '0';
            l++;
        }
        int before = 1, after = 1;
        while(ones == k && l < r && s[l] == '0'){
            l++;
            before++;
        }
        while(ones == k && r < s.size() && s[r] == '0'){
            r++;
            after++;
        }
        if(ones == k){
            result += (before * after);
        }
            
    }
    cout << result;
}