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
    string s;
    cin>>s;
    int n = s.size(), ans=0;
    Fo(i,1,n){
        if((s[i] == 'x' && s[i-1] == 'y') || (s[i]== 'y' && s[i-1]=='x')){
            ans++;
            s[i]= 'a';
            s[i-1]= 'a';
        }
        if((s[i]== 'x' && s[i+1]=='y') || (s[i]=='y' && s[i+1]=='x')){
            ans++;
            s[i] = 'a';
            s[i+1] = 'a';
        }
    }
    cout<<ans<<endl;

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
