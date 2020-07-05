#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define fo(i,a) for(ll i=0;i<a;i++)
#define Fo(i,a,n) for(ll i=a; i<n; i++)

using namespace std;

void solve(){
    int n;
    cin>>n;
    int ans;
    if(n%1000 == 0) cout<<0;
    else cout<<1000- (n%1000);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
 //   cin >> t;
    while(t--)
        solve();
    return 0;
}
