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
int test, n, m, k, q;
void solve(){
    cin >> n >> q;
    vector<int> a(n);
    for(int &i:a) cin >> i;
    vector<int> b = a;
    for(int i = 1; i < n; i++) b[i] = min(b[i], b[i-1]);
    set<vector<int>> s;
    for(int i = 0; i < n; i++){
        int j = i;
        while(b[j] == b[i] && j < n) j++;
        j--;
        vector<int> tmp = {i+1, j+1, b[i]};
        s.insert(tmp);
        i = j;
    }

    debug() << deb(s);

    while(q--){
        int k, d;
        cin >> k >> d;
        a[k-1] -= d;
        vector<int> x = {k, inf, 0};
        auto it = s.upper_bound(x);
        debug() << deb("OK");
        it--;
        vector<int> curr = *it;
        if(curr[2] <= a[k-1]){
            cout << s.size() << ' ';
            debug() << deb(k) deb(d);
            continue;
        }
        debug() << deb("OK");
        s.erase(it);
        if(k == curr[0]){
            curr[2] = a[k-1];
            s.insert(curr);
        }else{
            vector<int> prv = {curr[0], k-1, curr[2]};
            vector<int> nxt = {k, curr[1], a[k-1]};
            s.insert(nxt);
            s.insert(prv);
        }
        int last =0;
        bool ok = false;
        while(!s.empty()){
            it = s.upper_bound(x);
            it--;
            auto it2 = it;
            it2++;
            if(it2 == s.end()) break;
            if((*it)[2] <= (*it2)[2]){
                last = (*it2)[1];
                s.erase(it2);
                ok = true;
            }else break;
        }
        // debug() << deb("OK");
        if(ok){
            it = s.upper_bound(x);
            it--;
            int f = (*it)[0], se = (*it)[2];
            s.erase(it);
            vector<int> tmp = {f, last, se};
            s.insert(tmp);
        }
        // debug() << deb("OK");
        cout << s.size() << ' ';
        debug() << deb("OK");
    }
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
