#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MOD (ll)1e9+7

class Solution {
public:
	void solve() {
		int n;
		cin >> n;
		cout << n << "\n";
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T = 1;
	// cin >> T;
	while (T--)	{
		Solution obj;
		obj.solve();
	}
	return 0;
}

ll pow(ll x, ll y) {
	ll r = 1;
	while (y > 0) {
		if (y & 1) r *= x;
		y = y >> 1;
		x = (x * x) % MOD;
	}
	return r;
}

ll expo(ll a, ll b) {
	ll r = 1;
	while (b > 0) {
		if (b & 1) r = (r * a) % MOD;
		a = (a * a) % MOD;
		b = b >> 1;
	}
	return r;
}
