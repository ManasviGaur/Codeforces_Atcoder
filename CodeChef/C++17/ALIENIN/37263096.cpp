#include <bits/stdc++.h>

using namespace std;

/******************************MACROS******************************/

#define int long long
#define ld long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define vt vector
#define pb push_back
#define F first
#define S second
#define u_s unordered_set
#define u_m unordered_map
#define p_q priority_queue

/******************************TEMPLATE******************************/

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifndef ONLINE_JUDGE
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define deb(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

/******************************ALGORITHMS******************************/

int __pow(int x, int y, int M) {int res = 1;while(y>0){if(y&1) res = (res*x)%M; y>>=1; x = (x*x)%M;}return res%M;}
int __pow(int x, int y) {int res = 1;while(y>0){if(y&1) res = (res*x); y>>=1; x = (x*x);}return res;}
int gcd(int a, int b) {if(b==0) return a; return gcd(b, a % b);}

/******************************MAIN*CODE******************************/
const int N = 1e5+2, inf = 1e18, M = 998244353, T = 1e7;
int test, n, m, d, query;
vt<int> a;

bool is(int x)
{
    ld time = (ld) x / T, timer = a[0] + time;
    for(int i = 1; i < n; i++)
    {
        if(timer > a[i] + d)
            return 0;
        timer = max(timer, (ld) a[i]) + time;
    }
    return 1;
}
int32_t main()
{
    cin>>test;
    while(test--){
        cin >> n >> d;
    a.clear();
    for(int i=0; i<n; i++) a.pb(0);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(all(a));
    int l = 0, r = inf, res = -1;
    while(r>=l)
    {
        int m = (l + r) / 2;
        if(is(m))
            res = m, l = m + 1;
        else
            r = m - 1;
    }
    cout << setprecision(9) << fixed << (ld) res / T << endl;
    }
    return 0;
}