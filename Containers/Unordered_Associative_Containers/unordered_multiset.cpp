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
template<class T> void _print(unordered_multiset<T> v) {
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
		int arr[] = {9, 2, 5, 2, 1, 5, 5, 2, 2, 1, 6, 6, 7, 7, 8};
		unordered_multiset<int> st1, st2;

		// Insert elements
		cerr << "arr : [ ";
		for (auto e : arr) {
			cerr << e << " ";
			st1.insert(e);
			st2.emplace(e);
		}
		cerr << "]\n";
		debug(st1);
		debug(st2);
		auto len = st1.size();
		debug(len);

		// copy and clear
		unordered_multiset<int> st3 = st1;
		unordered_multiset<int> st4(st2.begin(), st2.end());
		debug(st3);
		st3.clear();
		debug(st3);
		debug(st4);
		st4.erase(st4.begin(), st4.end());
		debug(st4);

		// erases specific elements
		st1.erase(2);
		debug(st1);
		auto it = st2.find(5); // returns an iterator pointing to the first occurance of 5
		st2.erase(it);	// deletes only that element to which the iterator is pointing to
		debug(st2);
		st2.erase(5);	// deletes all the occurances of 5 from the multiset
		debug(st2);
		debug(st1);
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
