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

int n, m, k, query;
vector<vector<int>> g;

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    g.resize(n+1);
    // vis.assign(n+1, false);
    map<int, bool> vis;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> query;
    int ans = 0;
    while(query--){
        vis.clear();
        int x, k;
        cin >> x >> k;
        queue<pair<int,int>> q;
        q.push({0, x});
        vis[x] = true;
        ans = x;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int u = p.second, d = p.first;
            if(d == k) continue;

            for(int v: g[u]){
                if(!vis[v]){
                    vis[v] = true;
                    ans += v;
                    q.push({d + 1, v});
                }
            }
            // debug() << deb(vis) deb(ans);
        }
        // debug() << deb(query) deb(ans);
        cout << ans << endl;
    }
    
    return 0;
}
