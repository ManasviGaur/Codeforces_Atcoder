#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define fo(i,a) for(ll i=0;i<a;i++)
#define Fo(i,a,n) for(ll i=a; i<n; i++)

using namespace std;
ll n;

void solve(){
    cin>>n;
    ll a,b;
    set<int> x;
    set<int> y;
    fo(i,4*n-1){
        cin>>a>>b;
        if(x.count(a)){
            x.erase(x.find(a));
        }
        else{
            x.insert(a);
        }

        if(y.count(b)){
            y.erase(y.find(b));
        }
        else{
            y.insert(b);
        }
    }
    auto it1=x.begin();
    auto it2=y.begin();
    cout<<*it1<<" "<<*it2<<endl;
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
