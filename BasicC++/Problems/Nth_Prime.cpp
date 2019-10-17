#include<iostream>
#include<vector>
#define REP(a, b, c) for(int i=a;i<b;i+=c)
typedef long long ll;
#define n 5000002
using namespace std;

bool is_prime[10000001];
int main(){
    int num;
    cin>>num;

    for(int i=2;i<10000001;i++)
        is_prime[i]=true;

    is_prime[0]=is_prime[1]=0;
    for(int i=2;i<10000001;i++){
        if(is_prime[i] && (ll) i*i<(ll) 10000000){
            for(int j=i*i;j<10000000;j+=i)
                is_prime[j]=0;
        }
    }
    int c=0;
    int k=2;
    while (c<num & k<10000000)
    {
       if(is_prime[k]>0)
        c++;
      k++;
    }
    cout<<k-1<<endl;
}