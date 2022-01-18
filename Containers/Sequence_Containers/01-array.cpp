#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

// Gloabal Declaration
// Contains all 0
array<int, 10> arr1;

// Gloabal incomplete Declaration
// Contains declared values and 0-s
array<int, 10> arr2 = {1, 3, 7};

class Solution {
public:
	void solve() {

		// Local Declaration
		// Contains garbage value
		array<int, 10> arr3;

		// Local incomplete Declaration
		// Contains declared values and 0-s
		array<int, 10> arr4 = {1, 3, 7};

		// Fills with value given
		array<int, 10> arr5;
		arr5.fill(42);

		// Get/Print array elements
		for (int i = 0; i < 10; i++) {
			cout << arr1.at(i) << "  ";
			cout << arr2.at(i) << "  ";
			cout << arr3.at(i) << "  ";
			cout << arr4.at(i) << "  ";
			cout << arr5.at(i) << endl;
		}
		cout << endl;
		for (int i = 0; i < 10; i++) {
			cout << arr1[i] << "  ";
			cout << arr2[i] << "  ";
			cout << arr3[i] << "  ";
			cout << arr4[i] << "  ";
			cout << arr5[i] << endl;
		}
		cout << endl;
		cout << "SIZE : " << arr4.size() << endl;
		cout << "MAX_SIZE : " << arr4.max_size() << endl;
		cout << "Is arr4 Empty(?) : " << arr4.empty() << endl << endl;

		// Swappig of arrays
		array<int, 5> a = {1, 2, 3, 4, 5};
		array<int, 5> b = { -10, -20, -30, -40, -50};
		cout << "Before Swapping: " << endl;
		cout << "a   b" << endl;
		for (int i = 0; i < 5; i++) {
			cout << a[i] << "  ";
			cout << b[i] << endl;
		}
		a.swap(b);
		cout << "After Swapping: " << endl;
		cout << " a   b" << endl;
		for (int i = 0; i < 5; i++) {
			cout << a[i] << "  ";
			cout << b[i] << endl;
		}

		// Front And Back
		cout << endl << "Front : " << a.front() << " Back : " << a.back();
		cout << endl << "Front : " << b.front() << " Back : " << b.back();
		cout << endl << endl;
		for (auto it = a.begin(); it != a.end(); it++) {
			// cout << it << " ";
			cout << *it << " ";
		}
		cout << endl;
		for (auto itr = a.end() - 1; itr != a.begin() - 1; itr--) {
			// cout << itr << " ";
			cout << *itr << " ";
		}
		cout << endl;
		for (auto itr = a.rbegin(); itr != a.rend(); itr++) {
			// cout << itr << " ";
			cout << *itr << " ";
		}
		cout << endl;
		for (auto it : a) {
			cout << it << " ";
		}
		cout << endl;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	Solution obj;
	obj.solve();
	return 0;
}
