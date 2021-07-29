#include <bits/stdc++.h>

using namespace std;

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


int __pow(int x, int y, int m) {int res = 1;while(y>0){if(y&1) res = (res*x)%m; y>>=1; x = (x*x)%m;}return res%m;}
int __pow(int x, int y) {int res = 1;while(y>0){if(y&1) res = (res*x); y>>=1; x = (x*x);}return res;}
int gcd(int a, int b) {if(b==0) return a; return gcd(b, a % b);}
int mi(int x, int M) { return __pow(x,M-2, M);}
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}

const int N = 1e5, inf = 1e17, M = 1e9 + 7;
int test,n,x,y,m,k,query;

void solve(){
    string s, t;
    cin>>s>>t;
    int n = s.size(), m = t.size();
    vt<vt<int>> dp(n+1, vt<int> (m+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
            if(s[i-1]==t[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            else dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
        }
    }
    debug()<<deb(dp);
    if(dp[n][m]==0) {
        string a = "";
        cout<<a<<endl;
        return;
    }
    vt<char> ans;
    int i = n, j = m;
    while(dp[i][j]!=0){
        if(dp[i][j]==dp[i-1][j-1]){
            i--;
            j--;
            continue;
        }
        if(dp[i][j]==dp[i-1][j-1] + 1 && s[i-1]==t[j-1]){
            ans.pb(s[i-1]);
            i--;
            j--;
            continue;
        }
        if(dp[i][j] == dp[i-1][j]){
            i--;
            continue;
        }
        if(dp[i][j] == dp[i][j-1]){
            j--;
        }
    }
    for(int i=ans.size()-1; i>=0; i--) cout<<ans[i];
    cout<<endl;

}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test=1;
    //cin>>test;
    while(test--){
        solve();
    }
    #ifndef ONLINE_JUDGE
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
