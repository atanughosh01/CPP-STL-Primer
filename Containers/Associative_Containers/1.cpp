// Problem: https://www.codechef.com/START60B/problems/FLIPPAL

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define ll          long long
#define ld          long double
#define ull         unsigned long long
#define endl        "\n"
#define ff          first
#define ss          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define vi          vector<int>
#define vll         vector<ll>
#define vvi         vector<vi>
#define vvll        vector<vl>
#define vpii        vector<pii>
#define vpll        vector<pll>
#define getidx      order_of_key
#define sz(x)       ((int)(x.size()))
#define all(x)      (x).begin(),(x).end()
#define rall(x)     (x).rbegin(),(x).rend()
#define minv(v)     *min_element(all(v))
#define maxv(v)     *max_element(all(v))
#define fill(x,y)   memset(x,y,sizeof(x))
#define type(x)     typeid(x).name()
#define rep(i,a,b)  for(auto i=(a);i<(b);++i)
#define REP(i,a,b)  for(auto i=(a);i<=(b);++i)
#define input(a,n)  rep(i,0,n) cin>>a[i];
#define output(a,n,s)rep(i,0,n) cout<<a[i]<<s;
#define setbits(x)  __builtin_popcount(x)
#define setbitsll(x)__builtin_popcountll(x)
#define prcs cout.precision(15);cout<<fixed;
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define pbds tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = ((ll)(1e18));
const ll MOD = ((ll)(1e9 + 7));
const ll MOD2 = ((ll)998244353);
const ld PI = ((ld)(acos(-1.0)));
const int N = 2e5 + 12;

// int arr[N], pre[N], dp[M];
// priority_queue<int, vector<int>, greater<int>> pq;

/*************************************************************************************/

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int c0 = 0, c1 = 0;
	for (char &c : s) {
		c0 += (c == '0');
		c1 += (c == '1');
	}
	cout << ((c0 % 2 && c1 % 2) ? "NO" : "YES");
}

int main() {
	prcs; fast;
#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
	freopen("zout.txt", "w", stdout);
	freopen("zerr.txt", "w", stderr);
#endif
//  auto start = high_resolution_clock::now();
	int _TT = 1;
	cin >> _TT;
	for (int _i = 1; _i <= _TT; _i++) {
		// cout << "Case #" << _i << ": ";
		solve();
		cout << endl;
	}
//  auto stop = high_resolution_clock::now();
//  auto duration = duration_cast<nanoseconds>(stop - start);
// #ifndef ONLINE_JUDGE
//  cerr << "\n[Completed in " << ((ld)duration.count()) / ((ld)1e9) << " s]" << endl;
// #endif
	return 0;
}
