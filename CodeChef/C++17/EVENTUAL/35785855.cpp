#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define fo(i,a) for(ll i=0;i<a;i++)
#define Fo(i,a,n) for(ll i=a; i<n; i++)

using namespace std;
ll n,k,x,m;

void solve()
{
    cin>>n;
    string s;
    cin>>s;
    unordered_map<char,ll> cnt;
    fo(i,n){
        cnt[s[i]]++;
    }
    bool flag=true;
    fo(i,n){
        if(cnt[s[i]]%2==1){
            flag=false;
            break;
        }
    }
    if(flag)cout<<"YES\n";
    else cout<<"NO\n";
}
int main()
{
 //   ios_base::sync_with_stdio(NULL);
 //   cin.tie(NULL);
 //   cout.tie(NULL);
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
