#include <bits/stdc++.h>

using namespace std;


int main(){
    string s;
    cin >> s;
    vector<int> L(s.size()+1), R(s.size()+1);
    int lower_change = 0, upper_change = 0;
    for(int i=0; i<s.size(); i++){
        lower_change += islower(s[i])? 1: 0;
        R[i+1] = lower_change;
    }
    for(int i=s.size()-1; i>=0; i--){
        upper_change += isupper(s[i])? 1: 0;
        L[i] = upper_change;
    }

    int result = s.size();
    for(int i=0; i<=s.size(); i++){
        result = min(result, L[i] + R[i]);
    }
    cout << result;

}