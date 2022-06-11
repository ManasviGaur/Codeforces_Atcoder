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
    ll a,b,l,r,ans=0;
    cin>>a>>b>>l>>r;
    ll L = l - l%(a+b);
    ll R = r - r%(a+b);
    if(l==L && l!=0) ans++;
    if(L+a<l) ans--;
    ll temp = ((r/(a+b))-(l/(a+b)));
    ans+= temp*2;
    if(R+a>=L && R+a<=r) ans++;
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}