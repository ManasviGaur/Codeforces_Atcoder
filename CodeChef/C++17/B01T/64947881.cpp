#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <iomanip>
#include <tuple>
#include <list>
#include <bitset>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <stack>
#include <functional>
#include <utility>
#include <numeric>

using namespace std;
 
/******************************MACROS******************************/
 
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
#define all0(x) memset((x), 0, sizeof((x)))

/*****************************DEBUGGING*TEMPLATE******************************/
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
 
const int N = 2e5+1, inf = 1e17, M = 1e9 + 7;
int test, n, m, k, query;
vector<vector<int>> g;
vector<int> wt, par;
map<int, int> mp;
int cnt1, cnt0;

void dfs(int i, int par, vector<pair<int,int>> &difff){
  if(wt[i]==1){
    difff[i].second++;
    cnt1++;
  }else{
    cnt0++;
    difff[i].first++;
  }

  for(int j: g[i]){
    if(j==par)
      continue;
    dfs(j,i,difff);
    difff[i].first+=difff[j].first;
    difff[i].second+=difff[j].second;
  }
}

bool dfs2(int i,int par,vector<pair<int,int>> &difff,vector<int> &ans, int &operations){
  for(int j: g[i]){
    if(j==par)
      continue;
    if(cnt0<cnt1){
      int diff=difff[j].first-difff[j].second;
      diff*=(-1);
      if(diff<0){
        bool res=dfs2(j,i,difff,ans,operations);
        if(res)
          return true;
      }else{
        cnt0+=diff;
        cnt1-=diff;
        
        if(cnt0==cnt1){
            operations++;
            ans.push_back(j);
            return true;
        }else{
            if(cnt0>cnt1){
                cnt0-=diff;
                cnt1+=diff;
                bool res=dfs2(j,i,difff,ans,operations);
                if(res)
                    return true;
            }else{
                ans.push_back(j);
                operations++;
            }
        } 
      }
    }else{
        int diff=difff[j].first-difff[j].second;
        if(diff<0){
            bool res=dfs2(j,i,difff,ans,operations);
            if(res)
            return true;
        }else{
            cnt0-=diff;
            cnt1+=diff;
            if(cnt0==cnt1){
                ans.push_back(j);
                operations++;
                return true;
            }else{
                if(cnt1>cnt0){
                cnt0+=diff;
                cnt1-=diff;
                bool res=dfs2(j,i,difff,ans,operations);
                if(res)
                return true;
            }else{
                ans.push_back(j);
                operations++;
            }
        }

        }
    }
  
}
return false;
}
void solve(){
    g.clear();
    wt.clear();
    cin >> n;
    g.resize(n+1);
    wt.resize(n+1);
    for(int i =1; i<= n; i++) cin >> wt[i];
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    vector<pair<int,int>> difff(n+1,{0ll,0ll});

    dfs(1,0,difff);
    int operations=0;
    vector<int> ans;
    if(cnt0==cnt1){
        cout<<"0";
    }else{
    bool res=dfs2(1,0,difff,ans,operations);
    }

    cout<<operations<<endl;
    for(int i: ans)
    cout<<i<<" ";
    cout << endl;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    test = 1;
    cin >> test;
    for(int i = 1; i <= test; i++){
        //cout << "Case #" << i << ": ";
        solve();
    }
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    // #endif
    return 0;
}
