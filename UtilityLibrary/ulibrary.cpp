#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

class Solution {
   public:
    void solve() {
        // Your code here
        cout << "Hello, World!" << endl;
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
