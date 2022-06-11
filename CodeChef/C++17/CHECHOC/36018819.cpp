#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define fo(i,a) for(ll i=0;i<a;i++)
#define Fo(i,a,n) for(ll i=a; i<n; i++)
#define u_m unordered_map
#define u_s unordered_set
using namespace std;
ll n,m,x,y,z,k;

void solve(){
    cin>>n>>m>>x>>y;
    if(n==1 && m==1){
        cout<<x<<endl;
        return;
    }
    if(y>=2*x){
        cout<<n*m*x<<endl;
        return;
    }
    else if(y<2*x && y>x){
        if(n%2==0 || m%2==0){
            cout<<(y)*n*m/2<<endl;
        }
        else{
            cout<<max(x,y-x)*(m*n+1)/2 + min(x,y-x)*(m*n-1)/2<<endl;
        }
    }
    else{
        if(n%2==0 || m%2==0){
            cout<<y*n*m/2<<endl;
        }
        else cout<<y*(m*n+1)/2<<endl;
    }
}
int main(){
    ll t=1;
    cin >> t;
    for(ll i=1; i<=t; i++){
   //     cout<<"Case #"<<i<<':'<<endl;
        solve();
    }
    return 0;
}
