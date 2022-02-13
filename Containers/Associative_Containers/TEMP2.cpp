#include <iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int a = 0, b = 0, i, n;
		cin >> n;
		string s;
		cin >> s;
		for (i = 0; i < n; i++) {
			(s[i] == '0') ?
			a++ :
			b++;
		}
		if (n % 2 == 0) {
			if (a == b)
				cout << "YES\n";
			else if (a % 2 == 0 && b % 2 == 0)
				cout << "YES\n";
			else
				cout << "NO\n";
		} else
			cout << "YES" << endl;;
	}
	return 0;
}
