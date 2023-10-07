#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

// 5 1 2 4 4 3
// 1 2 3 4 5 6
// 9
// 5 4 4 3 2 1
/*


*/
void solve()
{
    int n;
    cin >> n;
    priority_queue<array<int, 2>> q;
    for (int j = 0; j < n; j++)
    {
        int bj;
        cin >> bj;
        q.push({bj, j});
    }
    int ans = 0;
    while (q.size() > 2)
    {
        vector<array<int, 2>> temp(3);
        temp[0] = {q.top()[1], q.top()[0]};
        q.pop();
        temp[1] = {q.top()[1], q.top()[0]};
        q.pop();
        temp[2] = {q.top()[1], q.top()[0]};
        q.pop();
        sort(all(temp));
        ans = max(ans, temp[1][1] + temp[0][1] + temp[2][1] - temp[2][0] + temp[0][0]);
        q.push({temp[1][1], temp[1][0]});
        if (abs(temp[1][0] - temp[2][0]) >= abs(temp[1][0] - temp[0][0]))
        {
            q.push({temp[0][1], temp[0][0]});
        }
        else
        {
            q.push({temp[2][1], temp[2][0]});
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
