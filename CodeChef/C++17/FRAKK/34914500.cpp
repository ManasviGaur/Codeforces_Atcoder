#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define fo(i,a) for(ll i=0;i<a;i++)
#define Fo(i,a,n) for(ll i=a; i<n; i++)

using namespace std;
ll n,k;
/*
int makelist(ll n, int a){
    double x=10*n/(a*1.0);
    int z=n/a;
    int y=(int)x-10*z;
//    cout<<x<<endl<<z<<endl<<y<<endl;
    if(y!=0){
        return y;
    }
    else{
        while(z>=10){
            z/=10;
        }
        return z;
    }
}
/*
void solve(){
    ll n=2;
    int a=7;
    int b=makelist(n,a);
    cout<<b;
}

void solve(){
    cin>>n;
    int a,b,c,q;
    cin>>a>>b>>c>>q;
    vl v;
    v.pb(n);
    ll query;
    ll i=0;
    for(;i<q;i++){
        cin>>query;
        while(query>v.size()-1){
            n=makelist(n,a);
          //cout<<n<<endl;;
            v.pb(n);
            n=makelist(n,b);
            //cout<<n<<endl;
            v.pb(n);
            n=makelist(n,c);
            //cout<<n<<endl;
            v.pb(n);
            }
        cout<<v[query]<<endl;
//    fflush(stdin);
        if(n==0) break;
    }
    for(;i<q;i++){
        cin>>query;
        cout<<0<<endl;
    }
}
*/
void solve(){
    ll p,q,ans=0;
    cin>>n>>p>>q;
    ll z;
    fo(i,n){
        z=10*(p%q);
        p=z/q;
        ans+=p;
        p=z%q;

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
