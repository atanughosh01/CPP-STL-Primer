#include <bits/stdc++.h>
using namespace std;

struct Node1 {
    string str;
    int num;
    double db;
    char x;
};

struct Node2 {
    string str;
    int num;
    double db;
    char x;

    Node2(string _str, int _num, double _db, char _x) {
        str = _str;
        num = _num;
        db = _db;
        x = _x;
    }
};

class Solution {
   public:
    void solve1() {
        Node1 ins;
        ins.str = "Atanu";
        ins.num = 54;
        ins.db = 75.83;
        ins.x = 'P';
        cout << ins.str << endl;
        cout << ins.num << endl;
        cout << ins.db << endl;
        cout << ins.x << endl;
    }

    void solve2() {
        Node2 ins = Node2("JUBCSE", 2023, 577.387, 'K');
        cout << ins.str << endl;
        cout << ins.num << endl;
        cout << ins.db << endl;
        cout << ins.x << endl;
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
        sol.solve1();
        cout << endl;
        sol.solve2();
    }
    cerr << "Time taken: " << (float)clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}