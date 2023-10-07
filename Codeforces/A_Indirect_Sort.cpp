#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, ao;
        cin >> n >> ao;
        n--;
        if(ao == 1){
            puts("Yes");
        } else{
            puts("No");
        }
        while(n--){
            cin >> ao;
        }
    }
}