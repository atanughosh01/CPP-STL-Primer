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
void _print(unordered_set<T> v) {
	cerr << "{ ";
	for (T i : v) {
		_print(i);
		cerr << " ";
	}
	cerr << "}";
}

template<class T>
void _print(unordered_set<T, greater<T>> v) {
	cerr << "{ ";
	for (T i : v) {
		_print(i);
		cerr << " ";
	}
	cerr << "}";
}

class Solution {
public:
	void solve() {
		int arr[] = {2, 5, 2, 1, 5, 5, 2, 2, 1, 6, 6, 7, 7, 8};
		unordered_set<int> st1;

		// Insert elements
		cerr << "arr : [ ";
		for (auto e : arr) {
			cerr << e << " ";
			st1.insert(e);	// O(1) time
		}
		cerr << "]\n";
		debug(st1);
		int len = st1.size();
		debug(len);

		// Erase elements
		st1.erase(st1.begin()); // st.erase(iterator)
		debug(st1);
		st1.erase(st1.find(5)); // st.erase(iterator)
		debug(st1);
		st1.erase(6); // st.erase(value)
		debug(st1);
		st1.erase(st1.begin(), st1.find(7)); // st.erase(startItr, endItr)
		debug(st1);

		// Copy
		unordered_set<int> st2(st1.begin(), st1.end());
		debug(st2);
		auto it = st2.find(6);
		debug(*it);
		cerr << "holululu\n";
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
