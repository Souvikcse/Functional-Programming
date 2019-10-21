#include<bits/stdc++.h>
typedef long long ll;
#define mod 1000000007;
#define N 1000001
using namespace std;

ll a[15];
ll freqPrimefact[N];
// bool pri[100005];
// void sieve(){
//     for(int i=2;i<100001;i++){
//         pri[i]=1;
//     }
//     for(int i=2;i<100001;i++){
//         if(pri[i]){
//             for(int j=i*i;j<100001;j+=i)
//                 pri[j]=0;
//         }
//     }
// }
bool isPrime(ll num){
    for(ll i=2;i<=sqrt(num);i++){
        if(num%i==0)
        return false;
    }
    return true;
}
int main(){
  //  sieve();
    int t;
    cin>>t;
    while (t--){
       int n;
       cin>>n;
       memset(freqPrimefact, 0, sizeof(freqPrimefact));
    for(int i=0;i<n;i++){
            cin>>a[i];
        }
    for(int i=0;i<n;i++){
       if(isPrime(a[i])){
        freqPrimefact[a[i]]++;
        continue;
       }
       int num=a[i];
       for(int p=2;p<=sqrt(a[i]);p++){
           while(num%p==0){
               freqPrimefact[p]++;
               num/=p;
           }
       }
        if(isPrime(num)){
		   freqPrimefact[num]++;
	   }
    }
    ll ans=1;
    for(int i=2;i<N;i++){
        if(freqPrimefact[i])
            ans=(ans*(freqPrimefact[i]+1))%mod;
    }
    cout<<ans<<endl;
    }
}