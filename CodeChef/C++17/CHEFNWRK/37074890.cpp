#include <bits/stdc++.h>
 
using namespace std;
 
/********************************MACROS********************************/
 
#define int long long
#define ld long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define vt vector
#define pb push_back
#define F first
#define S second
#define u_s unordered_set
#define u_m unordered_map
#define p_q priority_queue
 
/*******************************DEBUGGER*******************************/
 
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
int gcd(int a, int b) {if(b==0) return a; return gcd(b, a % b);}
 
/******************************MAIN**CODE******************************/
 
const int N = 1e6+10, inf = 1e18, M = 1e9+7;
int test, n, m, k, query;
void test_case(){
    cin>>n>>k;
    vt<int> a(n);
    for(auto &p:a) cin>>p;
    int ans=0;
    bool flag=1;
    for(int i=0; i<n && flag; i++){
        if(a[i]>k) flag=0;
        int w=a[i];
        for(;i<n-1 && a[i+1]+w<=k && flag; i++){
            w+=a[i+1];
            if(a[i+1]>k) flag=0;
        }
        ans++;
    }
    if(!flag) cout<<-1<<endl;
    else cout<<ans<<endl;
}
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    test = 1;
    cin>>test;
    while(test--)
        test_case();
#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
