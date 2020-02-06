#include<iostream>
typedef long long ll;
using namespace std;

int main(){
    double p;
    cin>>p;
    if(p==0){
        cout<<"2";
        return 0;
    }
    p=1-p;
    double p1=1;
    int denom=365;
    int num=365;
    int ans=0;
    while (p1>p)
    {
        double f=(double)num/denom;
        p1*=f;
        num--;
        ans++;
    }
    cout<<ans;
}