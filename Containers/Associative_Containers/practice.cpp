#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
typedef long long ll;
typedef long double ld;


class NaiveSolution {
private:
	// Or we can use .substr(pos, len) function
	string sliceStr(string s, int l, int r) {
		string res = "";
		int n = (int)s.size();
		if (l >= r or l<0 or r>n)
			return res;
		for (int i = l; i < r; i++) {
			res += s[i];
		}
		return res;
	}

public:
	vector<int> findAnagrams(string s, string p) {
		int pn = (int)p.size();
		int sn = (int)s.size();

		sort(p.begin(), p.end());
		vector<int> idx;

		for (int i = 0; i + pn <= sn; i++) {
			string str = sliceStr(s, i, i + pn);
			sort(str.begin(), str.end());
			if (str == p) {
				idx.emplace_back(i);
			}
		}
		return idx;
	}
};


class OptimalSolution {
public:
	vector<int> findAnagrams(string s, string p) {
		int n = s.length(), m = p.length();
		vector<int> pv(26, 0), sv(26, 0), res;
		for (int l = 0; l < m; l++)
			pv[p[l] - 'a']++;
		int i = 0, j = 0;
		while (j < n) {
			sv[s[j] - 'a']++;
			if ((j - i + 1) < m) {
				j++;
			}
			else if ((j - i + 1) == m) {
				if (pv == sv)
					res.emplace_back(i);
				sv[s[i] - 'a']--;
				i++;
				j++;
			}
		}
		return res;
	}
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	auto start1 = high_resolution_clock::now();
	int T = 1;
	cin >> T;
	while (T--) {
		string s, p;
		cin >> s >> p;
		// NaiveSolution obj;
		OptimalSolution obj;
		vector<int> idxLst;
		idxLst = obj.findAnagrams(s, p);
		for (auto x : idxLst)
			cout << x << " ";
		cout << endl;
	}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop1 - start1);
	cerr << "\n[Completed in " << ((ld)duration.count()) / ((ld)1e9) << "s]" << endl;
	return 0;
}
