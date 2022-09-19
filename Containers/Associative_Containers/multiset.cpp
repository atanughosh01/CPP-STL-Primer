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
template<class T> void _print(multiset<T> v) {
	cerr << "[ ";
	for (T i : v) {
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template<class T> void _print(multiset<T, greater<T>> v) {
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
		int arr[] = {2, 5, 2, 1, 5, 5, 2, 2, 1, 6, 6, 7, 7, 8};
		multiset<int> st1;
		multiset<int, greater<int>> st2;
		multiset<int> st3;

		// Insert elements
		cerr << "arr : [ ";
		for (auto e : arr) {
			cerr << e << " ";
			st1.insert(e);	// O(log(n)) time, n = size of multiset
			st2.insert(e);	// O(log(n)) time, n = size of multiset
			st3.emplace(e);	// O(log(n)) time, n = size of multiset
		}
		cerr << "]\n";
		debug(st1);
		debug(st2);
		debug(st3);
		auto len = st1.size();
		debug(len);

		// erases specific elements
		st1.erase(2);
		debug(st1);
		auto it = st2.find(5); // returns an iterator pointing to the first occurance of 5
		st2.erase(it);	// deletes only that element to which the iterator is pointing to
		debug(st2);
		st2.erase(5);	// deletes all the occurances of 5 from the multiset
		debug(st2);
		debug(st1);

		// clears the whole container
		st3.clear();
		debug(st3);
		st2.erase(st2.begin(), st2.end());
		debug(st2);

		// Copy
		multiset<int, greater<int>> st4(st1.begin(), st1.end());
		multiset<int> st5 = st1;
		debug(st4);
		debug(st5);

		auto it1 = st3.find(6);
		debug(*it1);
		auto it2 = st3.find(9);
		debug(*it2);
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
	freopen("zout.txt", "w", stdout);
	freopen("zerr.txt", "w", stderr);
#endif
	int T = 1;
	cin >> T;
	while (T--) {
		Solution obj;
		obj.solve();
	}
	return 0;
}
