#include <bits/stdc++.h>
#define int int64_t
#define all(a) a.begin(), a.end()
#define range(a, f, t) a.begin() + f, a.begin() + t

using namespace std;

class DisjointSet
{
    vector<int> experience;
    vector<int> link;
    vector<int> offset;

public:
    DisjointSet(int n)
    {
        experience.resize(n + 1);
        offset.resize(n + 1);
        link.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            link[i] = i;
        }
    }

    void add(int x, int y)
    {
        experience[x] += y;
    }

    void join(int x, int y)
    {
        int xpar = get_parent(x);
        int ypar = get_parent(y);

        offset[xpar] += experience[xpar] - min(experience[xpar], experience[ypar]);
        offset[ypar] += experience[ypar] - min(experience[xpar], experience[ypar]);
        if (experience[xpar] < experience[ypar])
        {
            link[ypar] = xpar;
            experience[ypar] = experience[xpar];
        }
        else
        {
            link[xpar] = ypar;
            experience[xpar] = experience[ypar];
        }
    }

    int get(int x)
    {
        return experience[x] - min(experience[x], experience[get_parent(x)]) + offset[x];
    }

    int get_parent(int x)
    {
        if (x != link[x])
        {
            link[x] = get_parent(link[x]);
        }
        return link[x];
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    DisjointSet disjoin_set(n);
    for (int i = 0; i < m; i++)
    {
        string op;
        cin >> op;
        if (op == "add")
        {
            int x, y;
            cin >> x >> y;
            disjoin_set.add(x, y);
        }
        else if (op == "join")
        {
            int x, y;
            cin >> x >> y;
            disjoin_set.join(x, y);
        }
        else
        {
            int x;
            cin >> x;
            cout << disjoin_set.get(x) << endl;
        }
    }
}

int32_t main()
{
    solve();
}
