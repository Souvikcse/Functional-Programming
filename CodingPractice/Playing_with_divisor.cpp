#include<iostream>
typedef long long int ll;
using namespace std;

int mod = 1000000007;
int main(){
    int n;
    cin>>n;
    ll a[n];
    ll no_of_divisors = 1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        no_of_divisors = (no_of_divisors*((a[i]+1)%mod))%mod;
    }
    //cout << no_of_divisors << endl;
    ll f = (no_of_divisors * 500000004)%mod;
    ll ans = 1;
    for(int i=0;i<n;i++){
        a[i] = (a[i]*f)%mod;
        //cout << a[i] << " " ;
        ans = (ans * ((a[i]+1)%mod))%mod;
    }
    //ans %= mod;
    cout<< ans <<endl;
}