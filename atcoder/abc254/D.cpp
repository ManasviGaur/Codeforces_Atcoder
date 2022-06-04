#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <iomanip>

using namespace std;
int n, m, k, query;
vector<int> sieve(){
    vector<bool> prime(n+1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    vector<int> ans;
    for (int p = 2; p <= n; p++)
        if (prime[p])
            ans.push_back(p);
    
    return ans;
}
vector<int> fun(int x, vector<int> &pr){
    // vector<bool> ans(m, false);
    vector<int> ans;
    for(int i = 0; i < m && x > 1; i++){
        int cnt = 0;
        while(x%pr[i] == 0){
            cnt++;
            x /= pr[i];
        }
        // if(cnt&1) ans[i] = true;
        if(cnt&1) ans.push_back(pr[i]);
        if(x < pr[i]) break;
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<int> pr = sieve();
    m = pr.size();
    // cout << m << endl;
    map<vector<int>, int> cnt;
    for(int i=1; i <= n; i++){
        cnt[fun(i, pr)]++;
    }
    int ans = n;
    for(auto [p,q]: cnt){
        ans += q*(q-1);
    }
    cout << ans << endl;
    return 0;
}
