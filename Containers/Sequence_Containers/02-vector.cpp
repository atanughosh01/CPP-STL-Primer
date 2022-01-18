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
template<class T> void _print(vector<T> v) {
	cerr << "[ ";
	for (T i : v) {
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}

// Actual code starts from here
class Solution {
public:
	void solve1() {
		// Initialize, push, pop, clear, copy, iterate
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

		vector<int> vec6(vec2.begin() + 1, vec2.begin() + 4);
		debug(vec6);


		// Size and capacity
		vector<int> vec7;
		for (int i = 1; i <= 10; i++)
			vec7.emplace_back(i * 10);
		debug(vec7);
		cout << "Size : " << vec7.size();
		cout << "\nCapacity : " << vec7.capacity();
		cout << "\nMax_Size : " << vec7.max_size();

		// Pointer to the first element
		int* pos = vec7.data();
		cout << "\nThe fourth element is " << *(pos + 3) << endl;


		// Swapping of vectors
		vector<int> v1 = { -1, 22, -28, 999};
		vector<int> v2 = {10, 11, 12};
		cerr << "\nBefore Swapping : " << endl;
		debug(v1); debug(v2);
		cerr << "\nAfter Swapping : " << endl;
		swap(v1, v2);
		debug(v1); debug(v2); cerr << endl;


		// emplace
		vector<int> vec = { 10, 20, 30 };
		vec.emplace(vec.begin() + 1, 15);
		vec.emplace(vec.end(), 45);
		debug(vec);
	}

	void solve2() {
		// 2D Vectors
		vector<vector<int>> vec2D;

		vector<int> v1;
		v1.emplace_back(1);
		v1.emplace_back(2);

		vector<int> v2;
		v2.emplace_back(10);
		v2.emplace_back(20);
		v2.emplace_back(99);

		vector<int> v3;
		v3.emplace_back(19);
		v3.emplace_back(24);
		v3.emplace_back(27);
		v3.emplace_back(-24);

		vec2D.emplace_back(v1);
		vec2D.emplace_back(v2);
		vec2D.emplace_back(v3);

		debug(v1); debug(v2); debug(v3);
		debug(vec2D);

		for (auto vtr : vec2D) {
			for (auto it : vtr) {
				cout << it << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < vec2D.size(); i++) {
			for (int j = 0; j < vec2D[i].size(); j++) {
				cout << vec2D[i][j] << " ";
			}
			cout << endl;
		}

		// 10x20
		vector<vector<int>> VEC2D(10, vector<int>(20, 1));
		for (auto vtr : VEC2D) {
			for (auto it : vtr) {
				cout << it << " ";
			}
			cout << endl;
		}
		cerr << endl; debug(VEC2D);
	}

	void solve3() {
		// 3D Vectors of size 3 x 4 x 5 having each element as 9
		// int arr[3][4][5]; memset(arr, 9, sizeof(arr));
		vector<vector<vector<int>>> VEC3D(3, vector<vector<int>> (4, vector<int>(5, 9)));
		for (auto vvtr : VEC3D) {
			for (auto vtr : vvtr) {
				for (auto it : vtr) {
					cout << it << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		debug(VEC3D);
	}
};


// Driver code
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	Solution obj;
	obj.solve1();
	cout << "\n-----------------\n\n";
	cerr << "\n-----------------\n\n";
	obj.solve2();
	cout << "\n-----------------\n\n";
	cerr << "\n-----------------\n\n";
	obj.solve3();
	return 0;
}
