#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve()
{
    int n, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int pi;
        cin >> pi;
        if (i + 1 == pi)
            count++;
    }

    cout << ceil(count / 2.0) << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
