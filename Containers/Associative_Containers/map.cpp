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
template<class T, class V> void _print(map<T, V> m) {
	cerr << "[ ";

	for (auto &[k, v] : v) {
		cerr << "{" << k << ":" << v << "}" << " ";

	for (auto &[k, v] : m) {
		cerr << "{" << k << ":" << v << "}";
		cerr << " ";

	}
	cerr << "]";
}

class Solution {
public:
	void solve() {
		map<int, int> m1;
		int arr[] = {2, 5, 2, 1, 5, 5, 2, 2, 1, 6, 6, 7, 7, 8};

		for (auto &e : arr) m1[e]++;

		for (auto e : arr) m1[e]++;

		debug(m1);
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
