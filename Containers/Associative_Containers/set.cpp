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
	cerr << "{ ";
	for (T i : v) {
		_print(i);
		cerr << " ";
	}
	cerr << "}";
}

template<class T>
void _print(set<T, greater<T>> v) {
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
		int arr[] = {2, 5, 2, 1, 5, 5, 2, 2, 1, 6, 6, 7};
		set<int> st1;
		set<int, greater<int>> st2;

		// Insert elements
		cerr << "arr : [ ";
		for (auto e : arr) {
			cerr << e << " ";
			st1.insert(e);	// O(log(n)) time, n = size of set
			st2.insert(e);
		}
		cerr << "]\n";
		debug(st2);
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

		// Copy & find
		set<int> st3(st2.begin(), st2.end());
		set<int, greater<int>> st4 = st2;
		debug(st3); debug(st4);
		auto it = st3.find(6);
		debug(*it);
		auto itr = st3.find(9);
		debug(*itr);
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
