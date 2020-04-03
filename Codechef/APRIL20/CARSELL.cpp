#include<iostream>
#include<algorithm>
typedef long long int ll;
using namespace std;

int mod = 1e9+7;
ll a[100001];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];

        ll k=0;
        ll ans = 0;
        sort(a, a+n);
        for(int i=n-1;i>=0;i++){
            ll price = max(0LL, a[i]-k);
            ans = (ans + price)%mod;
            k++;
        }
        cout << ans <<"\n";
    }
}