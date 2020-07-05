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
    ll n, cnt1=0, cnt2=0, cnt3=0, cnt4=0;
    cin>>n;
    string s;
    fo(i,n){
        cin>>s;
        if(s == "AC") cnt1++;
        if(s == "WA") cnt2++;
        if(s == "TLE") cnt3++;
        if(s == "RE") cnt4++;
    }
    cout<<"AC x "<<cnt1<<endl<<"WA x "<<cnt2<<endl<<"TLE x "<<cnt3<<endl<<"RE x "<<cnt4<<endl;
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
