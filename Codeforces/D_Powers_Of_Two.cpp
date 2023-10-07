#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> count(33);
    int total = 0;
    for(int i=0; i<32; i++){
        if((1<<i) & n){
            total += 1;
            count[i]++;
        }
    }
    for(int i=31; i>0; i--){
        while(((1<<i) & n) && total < k){
            total += 1;
            count[i]--;
            count[i-1]+=2;
            n |= (1<<(i-1));
            if(!count[i])
                n ^= (1<<i);
        }
    }
    if(total == k){
        puts("YES");
        for(int i=0; i<32; i++){
            while(count[i]){
                cout << (1<<i) << " ";
                count[i]--;
            }
        }
    } else {
        puts("NO");
    }
    
}