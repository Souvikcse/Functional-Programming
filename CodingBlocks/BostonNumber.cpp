#include<iostream>
#include<cmath>
typedef long long ll;
using namespace std;

int digit_sum(int n){
    int digit_sum=0;
     while (n>0)
    {
       digit_sum+=n%10;
       n/=10;
    }
    return digit_sum;
}
int compute(ll num){
    ll sum=0;
    ll n=num;
    for(int i=2;i<=sqrt(n);i++){
        while(num%i==0){
            num/=i;
            sum+=digit_sum(i);
        }
    }
    if(num!=1)
        sum+=digit_sum(num);

    ll dig_sum=digit_sum(n);
    if(sum==dig_sum)
        return 1;
    else
        return 0;
}
int main(){
    ll n;
    cin>>n;
    cout<<compute(n)<<endl;
}