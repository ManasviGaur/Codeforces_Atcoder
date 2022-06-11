#include <bits/stdc++.h>
#define int long long
#define ld long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vt vector
#define pb push_back
#define u_s unordered_set
#define u_m unordered_map
#define p_q priority_queue
#define ff first
#define ss second
using namespace std;
 
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
//void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
 
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
const int N=1e6+5;
int t, n, m, x, y, pf[N], cnt[N];

/*void solve(){
    cin>>n;
    vt<string> a(n);
    string mn, mx;
    int mni, mxi;
    for(int i=0; i<n; i++) cin>>a[i];
    mn=a[0], mx=a[0];
    for(int i=0; i<n; i++){
        int x=mn.compare(a[i]);
        int y=mx.compare(a[i]);
        if(x<0){
            mn=a[i];
            mni=i;
        }
        if(y>0){
            mx=a[i];
            mxi=i;
        }
    }
    int q;
    cin>>q;
    while(q--){
        int p;
        cin>>p;
        if(p==2){
            cout<<
    }
}*/
int32_t main()
{
    for(int i=2; i<N; i++){
        if(pf[i])
            continue;
        for(int j=i; j<N; j+=i){
            pf[j]=i;
        }
    }
    for(int i=2; i<N; i++){
        cnt[i]=cnt[i-1];
        if(pf[i]==i) cnt[i]++;
    }
    t = 1;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        if(n==2){
            cout<<1<<endl;
            continue;
        }
        cout<<(n-2)+(cnt[n]-1)<<endl;
    }
        #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
