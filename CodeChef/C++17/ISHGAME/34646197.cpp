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
    string a,b;
    cin>>a>>b;
    set<char> bs;
    fo(i,b.size()){
        bs.insert(b[i]);
    }
    fo(i,a.size()){
        bool flag=false;
        fo(j,bs.size()){
            if(bs.count(a[i])) flag=true;
        }
        if(!flag) cout<<a[i];
    }
    cout<<endl;
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
