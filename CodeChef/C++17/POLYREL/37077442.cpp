#include <bits/stdc++.h>

using namespace std;

/***********MACROS***********/

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
#define mp make_pair

const int N = 1e3+2, inf = 1e18, M = 1e9+7;

int test, n, m, k, query;
bool is = 0;

void test_case() {
    cin >> n;
    for(int i = 0, x, y; i<n; i++) {
		cin >> x >> y;
	}
	int ans = n;
	n /= 2;
	while(n>2) {
		ans += n;
		n /= 2;
	}
	cout << ans << endl;
}
int32_t main() {
    test = 1;
	scanf("%lld", &test);
    for(int i = 1; i <= test; i++) {
		//printf("Case #%lld: ", i);
		test_case();
	}
#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}