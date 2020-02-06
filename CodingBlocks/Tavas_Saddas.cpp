#include<iostream>
#include<cstring>
typedef long long ll;
using namespace std;

int main(){
    char a[20];
    cin>>a;

    ll ans=0;
    int len=strlen(a);

    ans=(1<<len) -2;
    int pos=0;
    for(int i=len-1; i>=0;i--){
        if(a[i]=='7')
           ans+= (1<<pos);

        pos++; 
    }
    cout<<ans+1<<"\n";
}