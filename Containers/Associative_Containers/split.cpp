#include<bits/stdc++.h>
using namespace std;

vector<string> split(string &s, const char &c) {
	int n = s.size(), l = 0, r = 0;
	s.push_back(c);
	vector<string> res;
	while (s[r] == c) r++;
	l = r;
	while (r < n) {
		while (s[r] != c) r++;
		string word = s.substr(l, r - l);
		res.push_back(word);
		while (s[r] == c) r++;
		l = r;
	}
	return res;
}

string reverseWords(string &s) {
	vector<string> v = split(s, ' ');
	if (v.size() == 1) return s;
	string res = v.back();
	for (int i = v.size() - 2; i >= 0; i--) {
		res += " " + v[i];
	}
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
	freopen("zout.txt", "w", stdout);
	freopen("zerr.txt", "w", stderr);
#endif
	string s = " Let's  ta+ke    Leet+Code contest   ";
	vector<string> v = split(s, ' ');
	for (auto &x : v) cout << x << "\n";
	return 0;
}
