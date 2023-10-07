#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve()
{
    int n, idletime;
    cin >> n >> idletime;
    vector<vector<int>> book(n);

    for (int i = 0; i < n; i++)
    {
        int id, amount, timestamp;
        cin >> id >> amount >> timestamp;
        book[i] = {timestamp, amount, id};
    }
    sort(all(book));
    auto prev = book[0];
    for (auto bid : book)
    {
        if (bid[0] - prev[0] >= idletime)
        {
            cout << prev[2] << endl;
            return;
        }
        else if (prev[1] == bid[1])
        {
            prev[0] = bid[0];
            prev[2] = min(prev[2], bid[2]);
        }
        else if (bid[1] > prev[1])
            prev = bid;
    }
    cout << prev[2] << endl;
}

int32_t main()
{
    solve();
}
