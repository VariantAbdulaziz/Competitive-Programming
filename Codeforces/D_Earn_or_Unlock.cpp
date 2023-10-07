#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &aj : a)
    {
        cin >> aj;
    }

    vector<int> p(n + 1);
    for (int i = n - 1; i > 0; i--)
    {
        int ansi = max(a[i], p[i + min(1ll, a[i])] - p[min(i + a[i], n)]);
        p[i] = p[i + 1] + ansi;
        cout << i << ":" << p[i] << " ";
    }
    cout << endl;
    cout << min(1ll, a[0]) << " " << min(1ll, a[0]) + a[0] << endl;
    cout << p[min(1ll, a[0])] - p[min(1ll, a[0]) + a[0]] << endl;
}

int32_t main()
{
    solve();
}
