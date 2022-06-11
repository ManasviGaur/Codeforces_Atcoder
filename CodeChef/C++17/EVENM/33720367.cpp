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
    int n,x;
    cin>>n;
    if(n==1){
        cout<<"1"<<endl;
    }
    else{
    for(int i=1; i < n*n;){
        for(int j=0;j<n;j++){
            cout<< i<<" ";
            i++;
        }
        cout<<endl;
        x=i;
        if(i < n*n){
        for(int j=n+x-1; j>=x; j--){
            cout<<j<<" ";
            i++;
        }
        cout<<endl;
        }
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
