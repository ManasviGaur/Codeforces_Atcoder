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
    int l,r;
		cin >>l>>r;
		int c = l, ans=0;
		int arr[] = {2,8,14,20};
		while(c<r){
			if((binary_search(arr,arr+4,c))){
				ans++;
			}else{
				ans = ans + 2;
			}
			c++;
		}
		if(binary_search(arr,arr+4,r-1)){
			ans = ans + 1;
		}
		cout << ans << endl;
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