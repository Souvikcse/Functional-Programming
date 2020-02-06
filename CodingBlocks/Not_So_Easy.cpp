#include<iostream>
#include<cstring>
typedef long long ll;
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
using namespace std;

int count(int mask){
    int c=0;
    while (mask>0)
    {
        if(mask&1)
            c++;

        mask>>=1;
    }
    return c;
}
int main(){
    int t;
    cin>>t;
    int prime[]={2, 3, 5, 7, 11, 13, 17, 19};
    while (t--) {
    ll n;
    cin>>n;
    ll ans=0;
    REP(1, 1<<8, 1){
        int count_SetBits=count(i);
        ll denom=1;
        int num=i, pos=0;
        while (num)
        {
           if(num&1)
            denom*=prime[pos];

          pos++;
          num>>=1;
        }
        if(count_SetBits&1)
            ans+=n/denom;
        else
            ans-=n/denom;
    }
    cout<<ans<<"\n";
    }  
}