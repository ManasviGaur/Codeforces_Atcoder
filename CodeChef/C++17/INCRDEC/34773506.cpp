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
    int n,x;
    cin>>n;
    vi arr;
    vi xx;
    fo(i,n){
        cin>>x;
        arr.pb(x);
    }
    sort(arr.begin(), arr.end());
    if(arr[n-1]==arr[n-2]){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0; i<n-2; i++){
//        if(i>2){
        if(arr[i]==arr[i+2]){
            cout<<"NO"<<endl;
            return;
        }
//        }
        if(arr[i]==arr[i+1]){
            xx.pb(arr[i]);
            arr[i]=-1;
        }
    }
    cout<<"YES"<<endl;
    fo(i,arr.size()){
        if(arr[i]!=-1) cout<<arr[i]<<" ";
    }
    for(int i=xx.size()-1; i>=0; i--){
        cout<<xx[i]<<" ";
    }
    cout<<endl;

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
