// Problem: https://www.codechef.com/FEB222B/problems/WCC

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
//------------------------------
#define ff first
#define ss second
#define endl "\n"
#define INF (ll)1e18
#define MOD (ll)1e9+7
#define MOD2 998244353
#define PI (ld)acos(-1.0)
#define MAX_INF 9223372036854775807
#define sz(x) ((ll)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fill(x,y) memset(x,y,sizeof(x))
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define output(a,n,s) FOR(i,0,n)cout<<a[i]<<s;
#define input(a,n) FOR(i,0,n) cin>>a[i];
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define pbds_getidx order_of_key
#define setbits(x) __builtin_popcountll(x)
#define prcs cout.precision(15);cout << fixed;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//-----------------------------------------------------------------------------------------------------------------------------------------------
#define deb1(a) cerr<<#a<<": "<<a<<endl;
#define deb2(a,b) cerr<<#a<<": "<<a<<", "<<#b<<": "<<b<<endl;
#define deb3(a,b,c) cerr<<#a<<": "<<a<<", "<<#b<<": "<<b<<", "<<#c<<": "<<c<<endl;
#define deb4(a,b,c,d) cerr<<#a<<": "<<a<<", "<<#b<<": "<<b<<", "<<#c<<": "<<c<<", "<<#d<<": "<<d<<endl;
#define deb5(a,b,c,d,e) cerr<<#a<<": "<<a<<", "<<#b<<": "<<b<<", "<<#c<<": "<<c<<", "<<#d<<": "<<d<<", "<<#e<<": "<<e<<endl;
#define deb6(a,b,c,d,e,f) cerr<<#a<<": "<<a<<", "<<#b<<": "<<b<<", "<<#c<<": "<<c<<", "<<#d<<": "<<d<<", "<<#e<<": "<<e<<", "<<#f<<": "<<f<<endl;
//-----------------------------------------------------------------------------------------------------------------------------------------------
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " : "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template<class T, class V> void _print(pair<T, V> p);
template<class T> void _print(vector<T> v);
template<class T> void _print(set<T> v);
template<class T> void _print(multiset<T> v);
template<class T, class V> void _print(map<T, V> v);
template<class T, class V> void _print(unordered_map<T, V> v);
template<class T> void _print(vector<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T> void _print(set<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T> void _print(multiset<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T> void _print(unordered_set<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T, class V> void _print(pair<T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template<class T, class V> void _print(map<T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T, class V> void _print(unordered_map<T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//-----------------------------------------------------------------------------------------------------------------------------------------------

// const int MAX_NUM = 200000;
// priority_queue<int,vector<int>,greater<int>> pq;
/* Pass an array of size 3 */
// void extendgcd(ll a,ll b,ll* v){if(b==0){v[0]=1;v[1]=0;v[2]=a;return;}extendgcd(b,a%b,v);ll x=v[1];v[1]=v[0]-v[1]*(a/b);v[0]=x;return;}
// ll msb(ll n){ll r=0;FOR(i,0,32){if((1ll<<i)==n) return(i+1);if(((1ll<<i)&n)==(1ll<<i)){if(n==i)r=i;else r=i+1;}} return(r+1);}
// ll aot(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){return abs(x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3);} // 2*(Area of triangle)
// ll mex(vector<ll>& v){set<ll> s;for(auto x:v)s.insert(x);ll r=0;for(auto it:s){if(it!=r)return r;++r;}return r;}
// ll phi(ll n){ll r=n;for(ll i=2;i*i<=n;i++){if(n%i==0){while(n%i==0)n/=i;r-=r/i;}}if(n > 1)r-=r/n;return r;}
// ll gcd(ll a,ll b) {if(a>b) swap(a,b);if(a==0) return 0;if(b%a) return gcd(a,b-a);return a;}
// ll lcm(ll a,ll b) {return (a/gcd(a,b)*b);}
// ll binexp(ll a,ll b,ll mod) {ll r=1;while(b){if(b&1) r=(r*1LL*a)%mod;a=(a*1LL*a)%mod;b=b>>1;} return r;}
// ll mminv(ll a,ll b) {ll arr[3];extendgcd(a,b,arr);return arr[0];}    // For non prime b
// ll mminvprime(ll n,ll mod) {return binexp(n,mod-2,mod);}
// ll mod_add(ll a, ll b, ll m) {a = a%m; b = b%m; return (((a + b) % m) + m)%m;}
// ll mod_mul(ll a, ll b, ll m) {a = a%m; b = b%m; return (((a * b) % m) + m)%m;}
// ll mod_sub(ll a, ll b, ll m) {a = a%m; b = b%m; return (((a - b) % m) + m)%m;}
// ll mod_div(ll a, ll b, ll m) {a = a%m; b = b%m; return (mod_mul(a,mminvprime(b,m),m)+m)%m;} // Only for prime m
// string to_binary(ll n){string s;while(n){s += to_string(n%2);n/=2;}reverse(all(s));return s;}
// char to_lower(char c){if(c>=97) return c;return c+32;}
// char to_upper(char c){if(c<97) return c;return c-32;}
// bool isPowerOf2(ll x){return x && (!(x&(x-1)));}
// bool isPalindromeV(vector<ll>& v){ll n=sz(v);FOR(i,0,n/2){if(v[i]!=v[n-i-1]) return false;}return true;}
// bool isPalindromeS(string& v){ll n=sz(v);FOR(i,0,n/2){if(v[i]!=v[n-i-1]) return false;}return true;}
// bool isPrime(ll n) {if(n<=1) return false; for(ll i=2;i*i<n;++i) {if(n%i==0) return false;} return true;}
// bool isSorted(vector<ll> v) {FOR(i,0,sz(v)-1) {if(v[i]>v[i+1]) return false;}return true;}
//-----------------------------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
	void solFunc() {
		int n;
		string s;
		cin >> n >> s;
		int C = 0, N = 0, D = 0;
		for (int i = 0; i < 14; ++i) {
			if (s[i] == 'C') ++C;
			else if (s[i] == 'N') ++N;
			else ++D;
		}
		if (C > N) cout << 60 * n << endl;
		else if (C < N) cout << 40 * n << endl;
		else cout << 55 * n << endl;
	}
};

int main() {
	prcs; fast;
#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
	freopen("zout.txt", "w", stdout);
	freopen("zerr.txt", "w", stderr);
#endif
	auto start = high_resolution_clock::now();
	int T = 1;
	cin >> T;
	while (T--) {
		Solution obj;
		obj.solFunc();
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
#ifndef ONLINE_JUDGE
	cerr << "\n[Completed in " << ((ld)duration.count()) / ((ld)1e9) << " s]" << endl;
#endif
	return 0;
}
