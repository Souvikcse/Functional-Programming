#include<bits/stdc++.h>
typedef long long ll;
#define Size(a) (int)sizeof(a)/sizeof(a[0])
using namespace std;

void print(char* C){
    while((*C)!= '\0'){
        cout<<*C;
        C++;
    }
  //  cout<<*C;
    cout<<"\n";
}
int main(){
    char c[100] = "Hello";
    int ar[5];
    cout<<ar[0]<<" "<<ar[1]<<" "<<ar[2];
    cout<<c<<"\n";
    print(c);
}