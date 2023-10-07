#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    set<string> p, both, e;
    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        p.insert(temp);
    }
    for(int i=0; i<m; i++){
        string temp;
        cin >> temp;
        if(p.find(temp) != p.end()) both.insert(temp);
        e.insert(temp);
    }
    int p_word_count = both.size() - both.size() / 2 + p.size() - both.size();
    int e_word_count = both.size() / 2 + e.size() - both.size();
    if(p_word_count > e_word_count) cout << "YES";
    else cout << "NO";
}