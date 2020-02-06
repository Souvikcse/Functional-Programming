#include<iostream>
typedef long long ll;
using namespace std;

ll power(int a, int b){
    if(b==0)
        return 1;

    ll ans=power(a, b/2);
    ans*=ans;
    if(b&1)
        ans=a*ans;
    
    return ans;
}
ll fastPower(int a, int b){
    ll res=1;
    while (b)
    {
      if(b&1)
        res*=a;
    a*=a;
    b>>=1;
    cout<<res<<" "<<a<<endl;
    }
    return res;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<power(a, b)<<endl;
    cout<<fastPower(a, b);
}