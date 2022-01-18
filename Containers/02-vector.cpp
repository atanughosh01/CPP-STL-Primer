#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

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
template<class T> void _print(vector<T> v) {
	cerr << "[ ";
	for (T i : v) {
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}

class Solution {
public:
	void solve1() {
		vector<int> vec1(3, 15);
		debug(vec1);
		vec1.push_back(5);
		vec1.push_back(23);
		debug(vec1);
		vec1.pop_back();
		debug(vec1);
		vec1.clear();
		debug(vec1);

		vector<int> vec2 = {10, 12, 11, 23};
		debug(vec2);
		vector<int> vec3(vec2.begin(), vec2.end());
		vector<int> vec4(vec2);
		vector<int> vec5 = vec2;
		debug(vec3); debug(vec4); debug(vec5);
		vec2.push_back(999);
		// debug(vec2); debug(vec3); debug(vec4); debug(vec5);

		vector<int> vec6(vec2.begin() + 1, vec2.begin() + 4);
		debug(vec6);

		// Size and capacity
		vector<int> g1;
		for (int i = 1; i <= 10; i++)
			g1.emplace_back(i * 10);
		debug(g1);
		cout << "Size : " << g1.size();
		cout << "\nCapacity : " << g1.capacity();
		cout << "\nMax_Size : " << g1.max_size();

		// Pinter to the first element
		int* pos = g1.data();
		cout << "\nThe fourth element is " << *(pos + 3) << endl;

		// Swapping of vectors
		vector<int> v1 = { -1, 22, -28, 999};
		vector<int> v2 = {10, 11, 12};
		cerr << "\nBefore Swapping : " << endl;
		debug(v1); debug(v2);
		cerr << "\nBefore Swapping : " << endl;
		swap(v1, v2);
		debug(v1); debug(v2);
	}

	void solve2() {
		// 2D Vectors
		vector<vector<int>> v;
		vector<int> v1(5, 7);
		vector<int> v2(10, 3);
		vector<int> v3(-3, 8);
		// for (auto vtr : v) {
		// 	for (auto it : vtr) {
		// 		cout << it << " ";
		// 	}
		// 	cout << endl;
		// }
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	int T = 1;
	// cin >> T;
	while (T--) {
		Solution obj;
		obj.solve1();
		cout << "\n-----------------\n";
		cerr << "\n-----------------\n";
		obj.solve2();
	}
	return 0;
}
