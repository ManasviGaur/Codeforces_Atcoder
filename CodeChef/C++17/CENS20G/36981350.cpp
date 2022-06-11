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

const int N = 3e5+2, inf = 1e18, M = 1e9+7;

int test, n, m, k, query;

void test_case(){
    string s;
    cin>>s;
    n=s.size();
    //unordered_map<char,int> cnt;
    int u=0,d=0,r=0,l=0;
    for(int i=0; i<n; i++){
        if(s[i]=='U') u++;
        if(s[i]=='D') d++;
        if(s[i]=='L') l++;
        if(s[i]=='R') r++;
    }
    int x,y;
    cin>>x>>y;
    cin>>query;
    while(query--){
        int x1,y1;
        cin>>x1>>y1;
        bool flag=1;
        if(x1>x){
            if(r<x1-x) flag=0;
        }
        if(x1<x){
            if(l<x-x1) flag=0;
        }
        if(y1>y){
            if(u<y1-y) flag=0;
        }
        if(y1<y){
            if(d<y-y1) flag=0;
        }
        if(flag){
            cout<<"YES "<<abs(x-x1) + abs(y-y1)<<'\n';
        }
        else{
            no;
        }
    }
}
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test = 1;
    cin>>test;
    while(test--)
        test_case();
#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
