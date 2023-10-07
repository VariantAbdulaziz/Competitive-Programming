#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      string foo;
      cin >> foo;
      for (int j = 0; j < n; j++) {
        if (foo[j] == '1') {
          g[i][j] = 1;
        }
      }
      g[i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
      vector<int> v;
      for (int j = 0; j < n; j++) {
        if (g[j][i]) {
          v.push_back(j);
        }
      }
      cout << v.size();
      for (int x : v) {
        cout << " " << x + 1;
      }
      cout << '\n';
    }
  }
  return 0;
}
