#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    string result; cin >> result;
    for(int i=1; i<n; i++){
        string cur; cin >> cur;
        for(int i=0; i<result.size(); i++){
            if(result[i] != cur[i]){
                if(result[i] == '?')
                    result[i] = cur[i];
                else if(cur[i] == '?');
                else result[i] = '*';
            }
        }
    }
    for(int i=0; i<result.size(); i++){
        if(result[i] == '?'){
            result[i] = 'a';
        } else if(result[i] == '*')
            result[i] = '?';
    }
    cout << result << endl;
}