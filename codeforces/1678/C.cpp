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
class BIT{ //1-based indexing
    int n, val;
    //if todo = multiply, val should be 1, if todo = min(), val should be inf, if todo = add or max, val = 0
    vector<int> bit;

public:
    BIT(int _n, int _val)
    {
        n = _n;
        val = _val;
        bit.assign(n + 1, val);
    }
    BIT(vector<int> a, int _val)
    { // a should be in 1-based indexing
        n = a.size() - 1;
        val = _val;
        bit = a;
        for (int i = 1; i <= n; i++)
        {
            int p = i + (i & -i); //index to parent
            if (p <= n)
                bit[p] = todo(bit[p], bit[i]);
        }
    }
    int todo(int a, int b) { return (a + b); }
    void update(int i, int delta)
    { //if todo is addition, delta = new val - old val

        for (; i <= n; i += (i & -i))
        {
            bit[i] = todo(bit[i], delta);
        }
    }
    
    int get(int i)
    {
        int res = val;
        for (; i; i -= (i & -i))
        {
            res = todo(res, bit[i]);
        }
        return res;
    }
};
void solve(){
    cin >> n;
    vector<int> arr(n);
    for(int &i:arr) cin >> i;
    vector<int> fb(n);
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j< n; j++){
            if(arr[i] > arr[j]) fb[i]++;
        }
    }
    
    int ans = 0;
    
    for(int c = 2; c < n - 1; c++){
        for(int b = 1; b < c; b++){
            if(arr[b] > arr[c]) fb[b]--;
        }
        vector<int> pf(n, 0);
        for(int i = 1; i< n; i++){
            pf[i] = pf[i-1] + fb[i];
        }
        for(int a = 0; a < c; a++){
            if(arr[a] < arr[c])
                ans += pf[c-1] - pf[a];
        }
    }
    cout << ans << endl;
}
void solve2(){
    cin >> n;
    vector<int> arr(n);
    for(int &i:arr) cin >> i;
    
    int ans = 0;
    
    for(int a = 0; a < n; a++){
        BIT l(n, 0), r(n, 0);
        for(int d = a + 1; d < n; d++)
            r.update(arr[d], 1);
        int curr = 0;
        for(int c = a + 1; c < n; c++){
            curr -= l.get(n) - l.get(arr[c] - 1);
            if(arr[a] < arr[c]) ans += curr;
            curr += r.get(arr[c] - 1) - r.get(0);
            r.update(arr[c], -1);
            l.update(arr[c], 1);   
        }
    }
    cout << ans << endl;
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
        solve2();
    }
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    // #endif
    return 0;
}
