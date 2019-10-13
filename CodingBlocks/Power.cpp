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
int main(){
    int a,b;
    cin>>a>>b;
    cout<<power(a, b)<<endl;
}