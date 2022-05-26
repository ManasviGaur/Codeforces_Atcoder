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

int test, n;

void solve(){
    vector<int> a(4);
    for(int &i:a) cin >> i;
    string s;
    cin >> s;
    n = s.size();
    debug() << deb(n);
    bool ans = true;
    // priority_queue<int> xa, xb;
    int cnt[2];
    cnt[0] = cnt[1] = 0;
    for(char c: s) cnt[c - 'A']++;
    if(cnt[0] != a[0] + a[2] + a[3] || cnt[1] != a[1] + a[2] + a[3]){
        cout << "NO" << endl;
        return;
    }
    multiset<int> xa, xb;
    int sum = 0;
    for(int i = 0, j = 0; i < n; i = j + 1){
        j = i;
        while(j+1 < n && s[j] != s[j+1]) j++;
        int len = j - i + 1;
        if(len&1){
            sum += len/2;
        } else{
            if(s[i] == 'A') xa.insert(len/2);
            else xb.insert(len/2);
        }
    }
    debug() << deb(xa) deb(xb);
    for(int i:xa){
        if(i <= a[2]) a[2] -= i;
        else sum += i-1;
    }
    for(int i:xb){
        if(i <= a[3]) a[3] -= i;
        else sum += i-1;
    }
    // while(!pq.empty()){
    //     pair<int, int> p = pq.top();
    //     pq.pop();
    //     int x = p.second == 2 ? 3 : 2;
    //     if(a[p.second] >= p.first){
    //         a[p.second] -= p.first;
    //     }else if(a[x] >= p.first){
    //         a[x] -= p.first;
    //     }else sum += p.first - 1;
    // }
    if(sum >= a[2] + a[3]) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    return 0;
}
