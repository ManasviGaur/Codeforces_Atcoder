#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define int long long

int test, n, m, k;
int cost(map<int, int> freq){
  int mx = 0, diff = 0;
    for(auto [p, q]: freq){
        if(q == 0) continue;
        diff++;
    }
    for(int i = 0; i <= n; i++){
        if(freq[i] == 0) break;
        mx = i + 1;
    }
    return (diff - mx);
}

pair<bool, int> check(vector<int> a, int tar, int curr, map<int, int> freq){
    if(curr >= tar){
      return {true, cost(freq)};
    }
    set<pair<int,int>> s;
    for(auto [p, q]: freq){
      if(p > tar && q > 0) s.insert({q, p});
    }

    int k1 = k;
    while(!s.empty() && k1 > 0 && curr < tar){
      pair<int, int> p = *s.begin();
      s.erase(s.begin());
      p.first--;
      freq[p.second]--;
      freq[curr]++;
      k1--;
      if(p.first > 0) s.insert(p);
      while(freq[curr]) curr++;
    }
    s.clear();

    if(curr < tar && k1 > 0){
      for(auto [p, q]: freq){
        if(p <= tar && q > 1) s.insert({q, p});
      }

      while(!s.empty() && k1 > 0 && curr < tar){
        pair<int, int> p = *s.begin();
        s.erase(s.begin());
        k1--;
        freq[p.second]--;
        p.first--;
        freq[curr]++;
        while(freq[curr]) curr++;
        if(p.first > 1) s.insert(p);
      }
    }

    while(!s.empty() && k1 > 0){
      pair<int, int> p = *s.begin();
      s.erase(s.begin());
      k1--;
      freq[p.second]--;
      freq[0]++;
      p.first--;
      if(p.first > 0) s.insert(p);
    }

    if(curr < tar) return {false, -1};
    return {true, cost(freq)};
}

void solve(){
    map<int, int> freq;
    cin >> n >> k;
    vector<int> a(n);
    for(int &i:a) cin >> i;
    if(n <= k){
      cout << 0 << endl;
      return;
    }
    sort(a.begin(), a.end());
    
    for(int i: a) freq[i]++;
    int mex = 0;
    for(int i = 0; i <= n; i++){
        if(freq[i] == 0) break;
        else mex = i+1;
    }
    
    int l = 0, r = n, ans = n;
    while(l <= r){
      int mid = l + (r-l)/2;
      pair<int, int> p = check(a, mid, mex, freq);
      if(p.first == false){
        r = mid - 1;
      }else{
        ans = min(ans, p.second);
        l = mid + 1;
      }
    }
    cout << ans << endl;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    return 0;
}
