#include <bits/stdc++.h>

using namespace std;

int solve(string& s, int start, int end){
    int positive = 0;
    for(int i=start; i<end; i++){
        positive += s[i] == '+'? 1: 0;
    }
    int n = end - start - positive;
    int found = s.find("--", start);
    while(found != string::npos && found + 1 < end && positive < n){
        positive++;
        n-=2;
        found = s.find("--", found + 2);
    }
    if(positive == n)
        return 1;
    else return 0;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, result = 0; cin >> n;
        string s; cin >> s;
        for(int i=0; i < n; i++){
            for(int j=i + 2; j <= n; j++){
                result += solve(s, i, j);
            }
        }
        cout << result << endl;
    }
}