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
    ll n;
    cin>>n;
    ll m[n][n];
    ll a[n];
    fo(i,n){
        a[i]=0;
        fo(j,n){
            cin>>m[i][j];
            if(m[i][j]!=-1) a[i]|=m[i][j];
        }
    }
/*    fo(i,n){
        for(int j=i; j<n; j++){
            if(m[i][j]==-1 || (a[i]&a[j])==m[i][j]) continue;
            a[j]|= m[i][j];
        }
    } */
    ll sum=0;
    fo(i,n){
        sum+=a[i];
    }
    cout<<sum<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    int t;
//    cin >> t;
//    while(t--)
        solve();
    return 0;
}
