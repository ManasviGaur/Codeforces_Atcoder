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

/******************************main*code******************************/
 
const int N = 2e5+1, inf = 1e17, M = 1e9 + 7;
int test, n, m, k, query;

void solve(){
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool all_zero = true;
    for (auto x : arr)
    {
        if (x > 0)
        {
            all_zero = false;
            break;
        }
    }
    if (all_zero)
    {
        cout << 0 << endl;
    return;
    }
    if (k == 0)
    {
        int ans = 0;
        for (auto x : arr)
        {
            ans += x;
        }
        cout << ans << endl;
        return;
    }
    set<int> pos;
    set<int, greater<int>> posG;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            pos.insert(i);
            posG.insert(i);
            pos.insert(i + n);
            posG.insert(i + n);
        }
    }
    vector<int> ans_arr(n, k);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            int val1 = *pos.lower_bound(i);
            int val2 = *posG.lower_bound(i + n);
            int dist = min(abs(val1 - i), abs(val2 - (i + n)));
            ans_arr[i] -= dist;
        }
    }
    for (auto &x : ans_arr)
    {
        if (x < 0)
        {
            x = 0;
        }
    }
    int sum = 0;
    for (auto x : arr)
    {
        sum += x;
    }
    for (auto x : ans_arr)
    {
        sum += 2LL * x;
    }
    cout << sum + m << endl;
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
    while(test--){
        solve();
    }
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    // #endif
    return 0;
}
