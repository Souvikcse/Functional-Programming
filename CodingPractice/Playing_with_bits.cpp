#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
using namespace std;

ll count_SetBits(int x, int y){
    ll ans=0;
    REP(x, y+1, 1){
        int num=i;
         while (num>0){
            ans+= (num&1);
            num>>=1; 
         }   
    }
    return ans;
}
int main(){
    int Q;
    cin>>Q;
    while(Q--){
        int x, y;
        cin>>x>>y;
        cout<<count_SetBits(x, y)<<"\n";
    }
}