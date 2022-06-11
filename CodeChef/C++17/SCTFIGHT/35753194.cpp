#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define fo(i,a) for(ll i=0;i<a;i++)
#define Fo(i,a,n) for(ll i=a; i<n; i++)

using namespace std;
ll n,m,k,x,y;

void solve(){
    cin>>n;
    vl a(n);
    fo(i,n){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll ans=1,rp;
    Fo(i,1,n){
        rp=1;
        while(a[i]==a[i-1] && i<n){
            rp++;
            i++;
        }
        ans=max(ans,rp);
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
