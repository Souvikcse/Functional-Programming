#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#define REP(a, b, c) for(int i=a;i<b;i+=c)
typedef long long ll;
#define N 1000001
using namespace std;

vector<int> sieve(){
    bool pri[N];
    vector<int> v;
   memset(pri, true, sizeof(pri));
    pri[0]=pri[1]=false;
    for(int i=2;i<N;i++){
        if(pri[i] && (ll) i*i<N){
            for(int j=i*i;j<N;j+=i)
                pri[j]=false;
        }
    }
    for(int i=2;i<N;i++){
       // cout<<i<<" "<<pri[i]<<"\n";
        if(pri[i]==true)
           { //cout<<i<<" ";
               v.push_back(i);}
    }
    return v;
}
int main(){
    vector<int> v=sieve();
    int t;
    cin>>t;
    while (t--)
    {
       ll m, n;
       cin>>m>>n;
        bool is_prime[(int)n-m+1];
        REP(0, n-m+1, 1){
            is_prime[i]=true;
        }
        for(int i=0;(ll)v[i]*v[i]<=n;i++){
            ll p=(ll)v[i];
            //cout<<p<<"\n";
            ll base=(m/p) ;
            base*=p;
            if(base<m)
                base+=p;

            for(ll j=base;j<=n;j+=p)
                is_prime[(int)j-m]=false;

            if(base == p)
                is_prime[(int) base-m]=true;
        }
        for(ll k=m;k<=n;k++){
         //   cout<<k<<" "<<is_prime[(int) k-m]<<"\n";
            if(is_prime[(int) k-m] && k!=1)
                cout<<k<<"\n";}
    //    cout<<"\n";
    }
}