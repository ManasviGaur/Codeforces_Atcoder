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

int fun(ll x){
    int sum=0;
    while(x!=0){
        sum+=x%10;
        x/=10;
    }
    return sum;
}

void solve(){
    cin>>n;
    ll temp;
    int chef=0, morty=0;
    stack<int> a;
    stack<int> b;
    fo(i,n){
        cin>>temp;
        a.push(fun(temp));
        cin>>temp;
        b.push(fun(temp));
    }
    fo(i,n){
        if(b.top()>a.top()) morty++;
        if(b.top()<a.top()) chef++;
        if(b.top()== a.top()){
            chef++;
            morty++;
        }
        a.pop();
        b.pop();
    }
    if(chef>morty) cout<<0<<" "<<chef<<endl;
    else if(chef<morty) cout<<1<<" "<<morty<<endl;
    else cout<<2<<" "<<chef<<endl;
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
