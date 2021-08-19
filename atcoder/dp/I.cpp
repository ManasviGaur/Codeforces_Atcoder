#include <bits/stdc++.h>

using namespace std;
 
/******************************MACROS******************************/
 
#define int long long
#define ld long double
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

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

int __pow(int x, int y, int m) {int res = 1;while(y>0){if(y&1) res = (res*x)%m; y>>=1; x = (x*x)%m;}return res%m;}
int __pow(int x, int y) {int res = 1;while(y>0){if(y&1) res = (res*x); y>>=1; x = (x*x);}return res;}
int gcd(int a, int b) {if(b==0) return a; return gcd(b, a % b);}
int mi(int x, int M) { return __pow(x,M-2, M);}
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}

/******************************main*code******************************/
 
const int N = 1e5+10, inf = 1e16, M = 1e9 + 7;
int test, n, m, k, query;
void solve(){
    cin >> n;
    vector<double> a(n);
    for(double &x:a) cin >> x;
    vector<vector<double>> dp(n+1, vector<double> (n+1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i][i] = dp[i-1][i-1]*a[i-1];
        dp[i][0] = dp[i-1][0]*(1 - a[i-1]);
    }

    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            dp[i][j] = dp[i-1][j] * (1 - a[i-1]) + dp[i-1][j-1]*a[i-1];
        }
    }
    debug() << deb(dp);
    double ans = 0.0;
    for(int i = 0; i <= n; i++){
        if(i > (n - i))
        ans += dp[n][i];
    }
    cout << setprecision(10) << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    test = 1;
    //cin >> test;
    while(test--)
        solve();
    #ifndef ONLINE_JUDGE
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}


