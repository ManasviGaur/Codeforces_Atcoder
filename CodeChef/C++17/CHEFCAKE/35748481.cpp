#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define fo(i,a) for(ll i=0;i<a;i++)
#define Fo(i,a,n) for(ll i=a; i<n; i++)

using namespace std;
ll n,m,k,x;
ll fact(ll a){
    ll ans=1;
    while(a>0){
        ans*=a;
        a--;
    }
    return ans;
}
void solve(){
    cin>>n;
    vl a(n);
  //  unordered_map<ll,ll> cnt;
    fo(i,n){
        cin>>a[i];
  //      cnt[a[i]]++;
    }
    x=1;
    ll ans=0;
    for(ll j=0;j<n;x*=10,j++){
    fo(i,n){
        ans+=a[i]*x;
    }
    }
    cout<<ans*fact(n-1)<<endl;
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
