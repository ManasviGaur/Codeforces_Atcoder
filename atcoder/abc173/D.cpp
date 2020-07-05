#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define fo(i,a) for(ll i=0;i<a;i++)
#define Fo(i,a,n) for(ll i=a; i<n; i++)

using namespace std;
/*
void solve(){
    int a,b,k,t=0;
    cin>>a>>b>>k;
    char arr[a][b];
    int row[a];
    int ca=ol[b];
    int tmp;
    fo(i,a){
        tmp=0;
        fo(j,b){
            cin>>arr[i][j];
            if(arr[i][j]=='#') tmp++,t++;
        }
        row[a]=tmp;
    }
    if(k>t){
        cout<<0<<endl;
        return;
    }
    fo(i,b){
        tmp=0;
        fo(j,a){
            if(arr[i][j]=='#') tmp++;
        }
        col[i]=tmp;
    }
    int x, ans=0;
    fo(i,a){
        fo(j,b){

        }
    }
}
*/
void solve(){
    ll n;
    cin>>n;
    vl arr(n);
    fo(i,n){
        cin>>arr[i];
    }
    sort(arr.rbegin(), arr.rend());
    ll ans=arr[0];
    n-=2;
    int i=1;
    while(n){
        ans+=arr[i];
        n--;
        if(n){
            ans+=arr[i];
            n--;
        }
        i++;
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
 //   cin >> t;
    while(t--)
        solve();
    return 0;
}
