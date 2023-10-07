#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

int n = 2e5;
auto is_prime = vector<int>(n);
void sieve()
{
    for (int i = 2; i <= n; i++)
        is_prime[i] = 1;
    // Removing multiples.
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * 2; j <= n; j += i)
                is_prime[j] = 0; // Eliminate multiples of i.
        }
    }
}
void solve()
{
    int n, count = 0, tp = 2;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        count++;
    }
    count /= 2;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && count--)
            cout << i << " ";
        else if (is_prime[i])
        {
            tp = i;
            break;
        }
    }
    cout << 1;
    for (int i = 2; i <= n; i++)
    {
        if (!is_prime[i])
            cout << " " << i;
    }
    for (int i = tp; i <= n; i++)
    {
        if (is_prime[i])
        {
            cout << " " << i;
        }
    }
    cout << endl;
}

int32_t main()
{
    sieve();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
