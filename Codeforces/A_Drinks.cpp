#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    double run = 0.0;
    for(int i=0; i<n; i++){
        int temp; cin >> temp;
        run += temp;
    }
    printf("%.12f", run / n);
}