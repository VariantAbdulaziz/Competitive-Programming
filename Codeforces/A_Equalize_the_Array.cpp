#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> book;
    map<int, int, greater<>> another;
    for (auto &aj : a)
        cin >> aj;

    for (auto aj : a)
        book[aj]++;

    for (auto [key, val] : book)
    {
        another[val]++;
    }
    int result = n;
    int count = 0;
    int sub = 0;

    int prevkey = -1;
    for (auto [key, val] : another)
    {
        sub += key * count;
        result = min(result, n - (sub + val) * key);
        sub -= key * val;
        count = val;
        prevkey = key;
    }
    cout << result << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
