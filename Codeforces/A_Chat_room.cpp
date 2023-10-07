#include <bits/stdc++.h>

using namespace std;
const string hello = "hello";

int main(){
    string s;
    cin >> s;
    for(size_t i=0, j=0; i<s.size(); i++){
        if(s[i] == hello[j]){
            j++;
        }
        if(j >= hello.size()){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    
}