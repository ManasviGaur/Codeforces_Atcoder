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
    ll temp1=0, temp2, sum=0;

    fo(i,n){
        cin>>temp2;
        if(i>0)
        sum+=abs(temp1-temp2)- (temp1==temp2?0:1);
        temp1=temp2;
    }
    cout<<sum<<endl;
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
