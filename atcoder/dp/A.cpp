#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define fo(i,a) for(ll i=0;i<a;i++)
#define fo1(i,a) for(ll i=1;i<a;i++)
#define Fo(i,a,n) for(ll i=a; i<n; i++)

using namespace std;
void solve();
const int N = 1e5+2;
ll dp[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  /*  int t;
    cin >> t;
    while(t--)*/
        solve();
    return 0;
}

void solve(){
    int n;
    cin >> n;
    vi h(n+1,0);
    fo(i,n) cin>>h[i];
    dp[1] = abs(h[1] - h[0]);
    dp[2] = min(dp[1] + abs(h[2]-h[1]), (ll)abs(h[0]-h[2]));
    Fo(i,3,n){
        dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    }
    cout<<dp[n-1]<<endl;
}
