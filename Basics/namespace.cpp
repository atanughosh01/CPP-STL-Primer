#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

namespace temp  {
	double val = 50.75;
	double getVal(double val) {
		return 2 * val;
	}
}

class Solution  {
public:
	double getVal(double val) {
		return 2 * val;
	}

	void solve() {
		double val = 10.50;

		cout << val << endl;
		cout << temp::val << endl;
		cout << getVal(val) << endl;
		cout << getVal(temp::val) << endl;
		cout << temp::getVal(val) << endl;
		cout << temp::getVal(temp::val) << endl;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	int T = 1;
	// cin >> T;
	while (T--)	{
		Solution obj;
		obj.solve();
	}
	return 0;
}
