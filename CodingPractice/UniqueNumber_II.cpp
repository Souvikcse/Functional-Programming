#include<iostream>
typedef long long ll;
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
using namespace std;

int arr[100001];
int main(){
    int n;
    cin>>n;
    REP(0, n, 1){
        cin>>arr[i];
    }
    int xor_sum=0;
    REP(0, n, 1){
        xor_sum^=arr[i];
    }
    int no=xor_sum;
    int pos=0;
    while (no){
        if(no&1)
            break;
        pos++;
        no>>=1;
    }
    int first=xor_sum;
    REP(0, n, 1){
        if((arr[i]& (1<<pos))!=0)
            first^=arr[i];
    }
    int second=xor_sum^first;
    cout<<first<<" "<<second<<endl;
}