#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

ll C(int n, int m){
    int num=1;
	ll ans=1;
	while(m--)
	{
		ans*=(n-m);
		ans/=num;
		num++;
	}
	return ans;
}

int main(){
    int n;
    cin >> n;
    ll ans = 0;
    for(int m=5; m<8; m++)
        ans += C(n, m);
    
    cout << ans;
}