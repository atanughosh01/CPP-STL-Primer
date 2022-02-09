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

template<class T>
void _print(set<T> v) {
	cerr << "[ ";
	for (T i : v) {
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}

template<class T>
void _print(set<T, greater<T>> v) {
	cerr << "[ ";
	for (T i : v) {
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}


class Solution {
public:
	void solve() {
		int arr[] = {2, 5, 2, 1, 5, 5, 2, 2, 1, 6, 6, 7};
		set<int> st1;
		set<int, greater<int>> st2;
		cerr << "arr : [ ";
		for (auto e : arr) {
			cerr << e << " ";
			st1.insert(e);
			st2.insert(e);
		}
		cerr << "]\n";
		debug(st1);
		debug(st2);
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
