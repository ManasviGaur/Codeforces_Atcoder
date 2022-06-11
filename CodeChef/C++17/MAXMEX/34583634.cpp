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
    int n,m,cntm=0;
    set<int> s;
    cin>>n>>m;
    int arr[n];
    fo(i,n){
        cin>>arr[i];
        if(arr[i]<m) s.insert(arr[i]);
        if(arr[i]==m) cntm++;
    }
    int x=s.size();
    if(x<m-1){
        cout<<"-1"<<endl;
        return;
    }
    else cout<<n-cntm<<endl;
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
