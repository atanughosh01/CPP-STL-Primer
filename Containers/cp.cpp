// Problem :

#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define endl "\n"
#define INF (ll)1e18
#define MOD (ll)1e9+7
#define MOD2 998244353
#define PI (ld)acos(-1.0)
#define ff first
#define ss second
#define V vector
#define G greater
#define UMP unordered_map
#define sz(x) ((ll)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define mems(x,y) memset(x, y, sizeof(x))
#define input(a,n) FOR(i,0,n) cin>>a[i];
#define output(a,n,sep) FOR(i,0,n) cout<<a[i]<<sep;
#define FOR(i,a,b) for(ll i=a; i<b; i++)
#define FORrev(i,a,b) for(ll i=a-1; i>=b; i--)
#define FORinc(i,a,b,c) for(ll i=a; i<b; i+=c)
#define FORdec(i,a,b,c) for(ll i=a-1; i>=b; i-=c)
#define set_bits __builtin_popcountll
#define preciseIO() cout.precision(15);cout << fixed;
#define fastIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//------------------------------------------------------------------------------------------------------------------------------------
#define deb1(a) cerr<<#a<<": "<<a<<endl;
#define deb2(a,b) cerr<<#a<<": "<<a<<", "<<#b<<": "<<b<<endl;
#define deb3(a,b,c) cerr<<#a<<": "<<a<<", "<<#b<<": "<<b<<", "<<#c<<": "<<c<<endl;
#define deb4(a,b,c,d) cerr<<#a<<": "<<a<<", "<<#b<<": "<<b<<", "<<#c<<": "<<c<<", "<<#d<<": "<<d<<endl;
#define deb5(a,b,c,d,e) cerr<<#a<<": "<<a<<", "<<#b<<": "<<b<<", "<<#c<<": "<<c<<", "<<#d<<": "<<d<<", "<<#e<<": "<<e<<endl;
#define deb6(a,b,c,d,e,f) cerr<<#a<<": "<<a<<", "<<#b<<": "<<b<<", "<<#c<<": "<<c<<", "<<#d<<": "<<d<<", "<<#e<<": "<<e<<", "<<#f<<": "<<f<<endl;
//------------------------------------------------------------------------------------------------------------------------------------
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
template<class T, class V> void _print(map<T, V> v);
template<class T> void _print(multiset<T> v);
template<class T, class V> void _print(pair<T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template<class T> void _print(vector<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T> void _print(set<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T> void _print(multiset<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T, class V> void _print(map<T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T, class V> void _print(UMP<T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//------------------------------------------------------------------------------------------------------------------------------------

// const int MAX_NUM = 200000;
// priority_queue<int, V<int>, G<int>> pq;
/* pass an arry of size 3 */
// void extendgcd(ll a,ll b,ll* v){if(b==0){v[0]=1;v[1]=0;v[2]=a;return;}extendgcd(b,a%b,v);ll x=v[1];v[1]=v[0]-v[1]*(a/b);v[0]=x;return;}
// ll gcd(ll a, ll b) {if(a>b) swap(a,b);if(a==0) return 0;if(b%a) return gcd(a,b-a);return a;}
// ll lcm(ll a, ll b) {return (a/gcd(a,b)*b);}
// ll pow(ll x, ll y) {ll r=1; while(y>0) {if(y&1) r*=x;y=y>>1;x=(x*x)%MOD;}return r;}
// ll expo(ll a, ll b, ll mod) {ll res=1; while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b=b>>1;} return res;}
// ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
// ll mminvprime(ll a, ll b) {return expo(a, b-2, b);}
// ll mod_add(ll a, ll b, ll m) {a = a%m; b = b%m; return (((a + b) % m) + m)%m;}
// ll mod_mul(ll a, ll b, ll m) {a = a%m; b = b%m; return (((a * b) % m) + m)%m;}
// ll mod_sub(ll a, ll b, ll m) {a = a%m; b = b%m; return (((a - b) % m) + m)%m;}
// ll mod_div(ll a, ll b, ll m) {a = a%m; b = b%m; return (mod_mul(a,mminvprime(b,m),m)+m)%m;} //only for prime m
// bool isPowerOf2 (ll x) {return x && (!(x & (x - 1)));}
// bool isPrime(ll n) {if(n<=1) return false; FOR(i,2,sqrt(n)+1) {if(n%i==0) return false;} return true;}
// bool isSortedArr(ll arr[], ll n) {FOR(i,0,n-1){if(arr[i]>arr[i+1]) return false;}return true;}
// bool isSortedVec(V<ll> v) {FOR(i,0,sz(v)-1){if(v[i]>v[i+1]) return false;}return true;}
//------------------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
	void solve() {
		int n; cin >> n;
		cout << n << endl;
	}
};

int main() {
	preciseIO();
	fastIO();
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#else
	//online submission
#endif
	auto start1 = high_resolution_clock::now();
	int T = 1;
	cin >> T;
	while (T--) {
		Solution obj;
		obj.solve();
	}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop1 - start1);
	cerr << "\n[Completed in " << ((ld)duration.count()) / ((ld)1e9) << "s]" << endl;
	return 0;
}
