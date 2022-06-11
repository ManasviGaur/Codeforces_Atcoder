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
    cin>>n>>k;
    vl a(n);
    fo(i,n) cin>>a[i];
    string s="";
    fo(i,n){
        if(a[i]%k==0){
            s+='1';
        }
        else s+='0';
    }
    cout<<s<<endl;
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
