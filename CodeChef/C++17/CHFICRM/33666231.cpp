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
    int n;
    cin>>n;
    int cnt5=0,cnt10=0,x;
    bool flag=true;
    fo(i,n){
        cin>>x;
        if(x==5){
            cnt5++;
        }
        if(x==10){
            if(cnt5){
                cnt5--;
                cnt10++;
            }
            else{
                flag = false;
            }
        }
        if(x == 15){
            if(cnt10){
                cnt10--;
            }
            else if(cnt5>=2){
                cnt5= cnt5 - 2;
            }
            else{
                flag = false;
            }
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;

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
