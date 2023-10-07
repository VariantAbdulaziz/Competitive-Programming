#include <bits/stdc++.h>
#define int int64_t

using namespace std;

class Book {
    set<int> book;
public:
    Book(vector<int>& a) {
        book = set(begin(a), end(a));
    }

    bool empty() {
        return book.empty();
    }

    int min() {
        if(empty())
            return -1;

        auto itr = book.begin();
        return *itr;
    }

    int max() {
        if(empty())
            return -1;

        auto itr = --book.end();
        return *itr;
    }

    void evictMin() {
        if(empty()) return;

        auto itr = book.begin();
        book.erase(itr);
    }

    void evictMax() {
        if(empty()) return;

        auto itr = --book.end();
        book.erase(itr);
    }
};

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &aj: a) {
        cin >> aj;
    }
    auto book = Book(a);
    int l = 0, r = n - 1;
    while(!book.empty() && (a[l] == book.min() || a[l] == book.max() 
                        || a[r] == book.min() || a[r] == book.max())) {

        if(a[l] == book.min()) {
            book.evictMin();
            l++;
        } 
        if(a[r] == book.min()) {
            book.evictMin();
            r--;
        }
        if(a[l] == book.max()) {
            book.evictMax();
            l++;
        }
        if(a[r] == book.max()) {
            book.evictMax();
            r--;
        }
    }
    if(!book.empty()) {
        cout << l + 1 << " " << r + 1;
    } else {
        cout << -1;
    }
}

int32_t main(){
    int t; cin >> t;
    while(t--) {
        solve();
        cout << endl;
    }
}
