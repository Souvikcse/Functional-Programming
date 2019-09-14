#include<bits/stdc++.h>
typedef long long ll;
#define Size(a) (int)sizeof(a)/sizeof(a[0])
using namespace std;

void printcombinations(char s[], int n, string out){
    if(n == 0){
        cout<<out<<"\n";
        return;
    }
    printcombinations(s+1, n-1, out+s[0]);
    printcombinations(s+1, n-1, out);
}
int main(){
    ios_base::sync_with_stdio(false);
    int a[5];
    ll n=5;
    a[0]=1;
    a[1]=2;
    a[2]=3;
    a[3]=4;
    a[4]=5;
    char c[10];
    // cout<<*a;
    // cout<<"\n"<<*(a+1);
    // cout<<"\n"<<(a+1);
    // cout<<"\n"<<a[1];
    // cout<<"\n"<<&a[1];
   // cout<<Size(c);
   char s[]={'r', 'a', 'j'};
    printcombinations(s, Size(s), "");
}