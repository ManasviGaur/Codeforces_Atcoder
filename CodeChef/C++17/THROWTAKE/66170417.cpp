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
#define F first
#define S second
#define u_s unordered_set
#define u_m unordered_map
#define p_q priority_queue
#define all0(x) memset((x), 0, sizeof((x)))

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}

/******************************main*code******************************/

int test, n, m, k, query;
void solve(){
    cin >> n;
    vector<int> a(n), b(n);
    for(int &i:b) cin >> i;
    for(int &i:a) cin >> i;
    vector<int> v;
    for(int i = 0; i < n; i++){
        if(b[i]&1) b[i] = 1;
        else b[i] = 2;
    }
    int curr = 0;
    if(b[n-1] == 1) curr = a[n-1];
    vector<vector<int>> dp(n, vector<int> (3, 0));
    dp[n-1][1] = a[n-1];
    for(int i = n-2; i >= 0; i--){
        dp[i][0] = curr;
        dp[i][1] = max(a[i] - dp[i][0], curr);
        if(b[i] == 2) dp[i][2] = max(a[i] - dp[i][1], curr);
        curr = max(curr, dp[i][b[i]]);
    }
    int ans = dp[0][b[0]];
    // n = v.size();
    // if(n == 0){
    //     cout << 0 << endl;
    //     return;
    // }
    // vector<vector<int>> dp(n, vector<int> (2, 0));
    // dp[n-1][1] = v[n-1];
    // int mx = 
    // for(int i = n-2; i >= 0; i--){

    // }
    // vector<int> mxind(n, n-1);
    // int curr = v[n-1];
    // for(int i = n-2; i >= 0; i--){
    //     if(a[i] > curr){
    //         curr = v[i];
    //         mxind[i] = i;
    //     }else{
    //         mxind[i] = mxind[i+1];
    //     }
    // }
    // int ans = 0;
    // bool flag = true;
    // for(int i =0; i < n; i++){
    //     if(flag){
    //         flag =!flag;
    //         i = mxind[i];
    //         ans += v[i];
    //     }else{
    //         flag = !flag;
    //         i = mxind[i];
    //         ans -= v[i];
    //     }
    // }
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
        solve();
    }
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    // #endif
    return 0;
}
