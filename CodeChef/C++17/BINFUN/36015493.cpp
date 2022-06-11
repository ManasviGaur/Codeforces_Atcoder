#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define vt vector
#define pb push_back
#define u_s unordered_set
#define u_m unordered_map
#define p_q priority_queue

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
// if using oset remove define int long long
//#define oset tree<int32_t, null_type, less<int32_t>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#define deb(x...) cout << "[" << #x << "] = ["; _print(x)
int __pow(int x, int y) {int res = 1;while(y>0){if(y&1) res*=x; y>>=1; x*=x;}return res;}
int gcd(int a, int b) {if(b==0) return a; return gcd(b, a % b);}
const int N = 3e5+2;

int t, n;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    t = 1;
    cin>>t;
    while(t--){
        cin>>n;
    vt<int> a(n), l[31];
    for(int &x:a)
        cin>>x;
    for(int i = 0; i<n; i++)
    {
        int tmp = log2(a[i]);
        l[tmp].pb(a[i]);
    }
    vt<int> b;
    int x = 0, y = 0;
    for(int i = 30; i>=0; i--)
        if(l[i].size()>0)
            b.pb(*max_element(all(l[i]))), b.pb(*min_element(all(l[i])));
    int mx = 0;
    for(int i = 0; i<b.size()-1; i++)
    {
        for(int j = i+1; j<b.size(); j++)
        {
            x = b[i], y = b[j];
            int lx = log2(x)+1;
            int ly = log2(y)+1;
            mx = max(mx, abs(x*(__pow(2, ly)-1)-y*(__pow(2, lx)-1)));
        }
    }
    cout<<mx<<endl;
    }
        
}