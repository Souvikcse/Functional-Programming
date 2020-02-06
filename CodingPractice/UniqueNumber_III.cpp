#include<iostream>
typedef long long ll;
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
using namespace std;

int main(){
    int bit[64]={0};
    ll ar[100001];
    int n;
    cin>>n;
    REP(0, n, 1){
        cin>>ar[i];
    }
    REP(0, n, 1){
        ll num=ar[i];
        int pos=0;
        while (num>0){
           if(num&1)
            bit[pos]+=1;

          num>>=1;
          pos++;
        }
    }
    ll ans=0;
    REP(0, 64, 1){
        bit[i]%=3;
        if(bit[i])
            ans|=(1<<i);
    }
    cout<<ans<<endl;
}