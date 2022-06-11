#include <bits/stdc++.h>
#include <vector>
#include <string>
#define ll long long int
#define ld long double
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define fo(i,a) for(ll i=0;i<a;i++)
#define Fo(i,a,n) for(ll i=a; i<n; i++)

using namespace std;

void solve(){
    ll ts,ans=0;
    cin>>ts;
    if(ts%2 != 0){
        cout<< (ts-1)/2 <<endl;
    }
    else{
        while(ts%2==0){
            ts/=2;
        }
        if(ts == 1){
            cout<<"0"<<endl;
        }
        else{
            cout<<(ts-1)/2<<endl;
        }
    }
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
