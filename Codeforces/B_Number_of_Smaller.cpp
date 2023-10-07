#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), stats(m);

    for (auto &aj : a)
        cin >> aj;
    for (auto &bj : b)
        cin >> bj;

    int l = -1;
    for (int r = 0; r < m; r++)
    {
        while (l + 1 < n && a[l + 1] < b[r])
        {
            l++;
        }
        stats[r] = l + 1;
    }
    for (auto sj : stats)
        cout << sj << " ";
}

int32_t main()
{
    solve();
}
