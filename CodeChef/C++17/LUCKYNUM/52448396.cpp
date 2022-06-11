#include <iostream>
using namespace std;
int test, n, m, k, query;
void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    bool res = false;
    if (a == 7 || b == 7 || c == 7) res = true;
    cout << (res ? "YES" : "NO") << endl;
}

int main(){
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
