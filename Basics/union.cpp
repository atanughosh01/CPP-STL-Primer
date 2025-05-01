#include <bits/stdc++.h>
using namespace std;

union Data {
    int i;
    float f;
    char c;
};

class Solution {
   public:
    void solve() {
        Data d;

        d.i = 42;
        cout << "d.i = " << d.i << endl;

        d.f = 3.14;
        cout << "d.f = " << d.f << endl;

        d.c = 'A';
        cout << "d.c = " << d.c << endl;

        // Accessing previous values is unsafe:
        cout << "d.i = " << d.i << " (corrupted due to c)" << endl;
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