#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int test, n, m, k, query;
void solve(){
    cin >> n;
    string s;
    cin >> s;
    int edg = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            edg += 2;
        }else{
            edg += 1;
        }
    }
    if((edg&1) || edg == 2*n){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    int i = 1;
    for(; i < n; i++) if(s[i-1] == '1') break;
    vector<pair<int, int>> ans;
    bool nw = true;
    for(int j = (i+1)%n; j != i; j = (j+1)%n){
        if(nw) ans.push_back({i, j});
        if(s[j] == '1'){
            nw = true;
        }else{
            ans.push_back({j, (j+1)%n});
            nw = false;
        }
    }

    for(auto p: ans){
        cout << p.first + 1 << ' ' << p.second + 1 << endl;
    }
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
