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
    cout<<"O";
    n--;
    fo(i,7){
        if(n>0) {
            cout<<".";
            n--;
        }
        else cout<<"X";
    }
    cout<<endl;
    for(int i=1;i<=7; i++){
        fo(i,8){
            if(n>0){
            cout<<".";
            n--;
            }
            else cout<<"X";
        }
        cout<<endl;
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
