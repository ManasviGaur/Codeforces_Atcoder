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
    int n, sum=0;
    cin>>n;
    int arr[n];
    fo(i,n) cin>>arr[i];

    sort(arr, arr+n);

    for(int i=n-3; i>=0; i-=3){
        sum+= arr[i];
    }
    cout<<sum<<endl;
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
