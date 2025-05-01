#include <bits/stdc++.h>
using namespace std;

namespace temp {
double val = 50.75;
double getVal(double val) { return 2 * val; }
}  // namespace temp

class Solution {
   public:
    double getVal(double val) { return 2 * val; }

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
    freopen("zin.txt", "r", stdin);
    freopen("zout.txt", "w", stdout);
    freopen("zerr.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution sol;
    int T = 1;
    // cin >> T;
    while (T--) {
        sol.solve();
    }
    cerr << "Time taken: " << (float)clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
