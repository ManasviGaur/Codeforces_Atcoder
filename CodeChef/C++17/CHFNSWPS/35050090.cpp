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

void solve(){
    cin>>n;
    unordered_map<ll,ll> cnt1, cnt2;
    vl a(n),b(n);
    ll mn=10e9,ans=0;
    set<ll> verify;
    fo(i,n){
        cin>>a[i];
        if(a[i]<mn) mn=a[i];
        cnt1[a[i]]++;

        if(verify.count(a[i])){
            verify.erase(verify.find(a[i]));
        }
        else verify.insert(a[i]);
    }

    fo(i,n){
        cin>>b[i];
        if(b[i]<mn) mn=b[i];
        cnt2[b[i]]++;

        if(verify.count(b[i])){
            verify.erase(verify.find(b[i]));
        }
        else verify.insert(b[i]);
    }

    if(verify.empty()){

        sort(a.begin(),a.end());
        sort(b.rbegin(), b.rend());

        for(ll i=0, j=0; i<n && j<n;){
            while(cnt1[a[i]]<=cnt2[a[i]] && i<n){
                i++;
            }
            while(cnt1[b[j]]>=cnt2[b[j]] && j<n){
                j++;
            }
            if(i>=n || j>=n) break;
            ll freq = min((cnt1[a[i]]-cnt2[a[i]])/2, (cnt2[b[j]]-cnt1[b[j]])/2);
            if(min(a[i],b[j])>2*mn){
                ans+=2*freq*mn;
            }
            else{
                ans+=freq*min(a[i],b[j]);
            }
            cnt1[a[i]]-=freq;
            cnt2[a[i]]+=freq;
            cnt1[b[j]]+=freq;
            cnt2[b[j]]-=freq;
        }

        cout<<ans<<endl;
    }
    else{
        cout<<"-1"<<endl;
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
