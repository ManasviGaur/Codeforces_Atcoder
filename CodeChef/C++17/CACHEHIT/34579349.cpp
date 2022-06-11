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
    int n,b,m,x=0,temp;
    cin>>n>>b>>m;
    vi s;
    fo(i,m){
        cin>>temp;
        s.pb(temp/b);
    }
    if(m!=0) x=1;
    fo(i,m-1){
        if(s[i]!=s[i+1]){
            x++;
        }
    }
    cout<<x<<endl;
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
