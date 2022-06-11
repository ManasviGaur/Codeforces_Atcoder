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
    ll n,s;
    cin>>s>>n;
    ll ans=0;
    if(s%2==1){
        ans++;
        s--;
    }
    ans+=(s/n);
    if(s%n!=0) ans++;
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
