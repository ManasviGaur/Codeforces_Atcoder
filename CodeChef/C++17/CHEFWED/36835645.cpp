#include <bits/stdc++.h>

#define int long long
#define ld long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define vt vector
#define pb push_back
#define u_s unordered_set
#define u_m unordered_map
#define p_q priority_queue

using namespace std;

const int N = 1e6+2, inf = 1e18, M = 1e9+7;

int test, n, m, k, query, fac[N], p[N];

int32_t main()
{
    cin>>test;
    while(test--)
    {
        cin>>n>>k;
        vt<int> a(n+1);
        for(int i = 1; i<=n; i++) cin>>a[i];
        vt<int> dp(n+1, inf);
        dp[0] = 0;
        for(int r = 1; r<=n; r++)
        {
        vt<int> sg(101);
        sg[a[r]]++;
        int sum = 0;
        for(int l = r-1; l>=0; l--)
            dp[r] = min(dp[r], dp[l]+k+sum), sum-=(sg[a[l]]>1 ? sg[a[l]] : 0), sg[a[l]]++, sum+=(sg[a[l]]>1 ? sg[a[l]] : 0);
        }
        cout<<dp[n]<<endl;
    }

    return 0;
}