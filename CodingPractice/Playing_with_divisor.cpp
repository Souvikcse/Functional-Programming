#include<iostream>
using namespace std;

int mod = 1e9+7;
int fastpow(int a, int b){
    int ans = 1;
    while(b){
        if(b&1)
            ans = (ans * a)%mod;

        a = (a * a)%mod;
        b>>=1;
    }
    return ans;
}

int main(){
    int x;
    cin>>x;
    int a[x];
    int sum = 0;
    for(int i=0;i<x;i++){
        cin>>a[i];
        sum += a[i];
    }

}