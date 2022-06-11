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

void solve(){
    cin>>n;
    vi a(n);
    fo(i,n){
        cin>>a[i];
    }
    ll q,x,y;
    cin>>q;
    while(q--){
            cin>>x>>y;
            auto it = lower_bound(a.begin(), a.end(), (x+y));
            if(it!=a.end() && *it==(x+y))
                cout<<-1<<endl;
            else
                cout<<(it-a.begin())<<endl;
    }
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

