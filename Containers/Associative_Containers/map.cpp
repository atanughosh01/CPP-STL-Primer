#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

// Debug Module
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " : "; _print(x); cerr << endl;
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template<class T, class V> void _print(map<T, V> v) {
	cerr << "[ ";
	for (auto i : v) {
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}

// template<class T, class V> void _print(map<T, V> v) {
// 	cerr << "[ ";
// 	for (auto i : v) {
// 		_print(i);
// 		cerr << " ";
// 	}
// 	cerr << "]";
// }

class Solution {
public:
	void solve() {
		// int n; cin >> n;
		// cout << n << "\n";
		auto x = 1ull << 63;
		cout << x << "\n";
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
	freopen("zout.txt", "w", stdout);
	freopen("zerr.txt", "w", stderr);
#endif
	int T = 1;
	// cin >> T;
	while (T--) {
		Solution obj;
		obj.solve();
	}
	return 0;
}
