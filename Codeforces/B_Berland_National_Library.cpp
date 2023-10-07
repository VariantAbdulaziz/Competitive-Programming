#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int room = 0, ans = 0;
    set<int> book;
    for(int i=0; i<n; i++){
        bool state;
        char c; cin >> c;
        state = (c == '+');

        int person;
        cin >> person;
        if(state){
            room++;
            book.insert(person);
        } else {
            if(book.find(person) == book.end()){
                ans = ans + 1;
            }
            else room--;
        }
        ans = max(ans, room);
    }
    cout << ans;
}