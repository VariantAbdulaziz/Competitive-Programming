#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a == 1)
    {
        cout << a + b << endl;
    }
    else
    {
        cout << a - 1 << endl;
    }
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
