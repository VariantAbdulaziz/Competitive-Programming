#include <bits/stdc++.h>
#define int int64_t

using namespace std;
typedef long long ll;

bool Q;
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const {
		return Q ? p < o.p : k < o.k;
	}
};
 
struct LineContainer : multiset<Line> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		Q = 1; auto l = *lower_bound({0,0,x}); Q = 0;
		return l.k * x + l.m;
	}
};

int32_t main(){
    int n; cin >> n;
    vector<int> x(n), y(n), a(n), dp(n + 1);
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i] >> a[i];
    }
    LineContainer lc;
    lc.add(0, 0);
    for(int i=1; i<=n; i++){
        dp[i] = x[i]*y[i] - a[i] + lc.query(y[i]);
        lc.add(-x[i], dp[i]);
    }
    for(auto aj: dp) cout << aj << " "; cout << endl;
    cout << dp[n] << endl;
}