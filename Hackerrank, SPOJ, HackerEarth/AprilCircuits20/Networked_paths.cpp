#include<iostream>
#include<cstring>
typedef long long ll;
#define N 3000002
using namespace std;

ll mod = 1e9+7;
ll X = 100000007700000049;
ll fac[N];
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;    
    x = x % p;
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 
  
ll modInverse(ll n, ll p) { 
    return power(n, p-2, p); 
} 
ll numberOfPaths(ll n, ll r) { 
   // Base case 
   if (r==0) 
      return 1; 
  
    return (fac[n]*(modInverse(fac[r], mod) % mod)*( modInverse(fac[n-r], mod) %mod))%mod;
} 
int main(){ 
    fac[0] = 1; 
    for (ll i=1 ; i<N; i++) 
        fac[i] = (fac[i-1]*i)%mod; 

	ll n, m, k, w;
	cin>>n>>m>>k>>w;
    ll ans = numberOfPaths(n+m-2, m-1);
    ll x, y;
    ll v;
    for(ll i=0;i<k;i++){
        cin>>x>>y>>v;
        if((v%X)==0){
			//cout << "hi";
            ans = (ans - numberOfPaths(x+y-2, y-1)+mod)%mod;
        }
    }
    for(ll i=0;i<k;i++){
        
    }
    cout << ans <<endl;
}