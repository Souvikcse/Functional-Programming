#include<iostream>
#include<cstring>
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
    cout<<xor_sum<<endl;
}