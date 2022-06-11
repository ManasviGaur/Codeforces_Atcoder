#include <bits/stdc++.h>
#include <math.h>
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ll long long int
#define ld long double
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define fo(i,a) for(ll i=0;i<a;i++)
#define fo1(i,a) for(ll i=1;i<a;i++)

using namespace std;


int main()
{
    int t;
    si(t);
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        fo(i,n){
            si(arr[i]);
        }
        vi cnts;
        vi nums;
        int cnt=1;
        for(int i=0; i<n; i++){

            if(arr[i]==arr[i+1]){
                cnt++;
            }
            else{
                cnts.pb(cnt);
                nums.pb(arr[i]);
                cnt=1;
            }
        }

        bool ans = true;
        int x= cnts.size();
        for(int i=0; i< x -1; i++){
            for(int j=i+1; j< x;j++ ){
                if(cnts[i] == cnts[j])
                    ans= false;
            }
        }
        int y= nums.size();
        for(int i=0; i< y -1; i++){
            for(int j=i+1; j< y;j++ ){
                if(nums[i] == nums[j])
                    ans= false;
            }
        }
        if(ans)
            cout<< "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
