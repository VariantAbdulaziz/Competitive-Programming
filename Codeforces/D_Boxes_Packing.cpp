#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    map<int, int> book, dp;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        book[temp]++;
    }

    cout << (*max_element(book.begin(), book.end())).second;
}