#include<iostream>
#include<cstring>
typedef long long ll;
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
using namespace std;

int main(){
    int x, y;
    cin>>x>>y;
    int L=x, R=y;
     int LXR = L ^ R; 
  
    //  loop to get msb position of L^R 
    int msbPos = 0; 
    while (LXR) 
    { 
        msbPos++; 
        LXR >>= 1; 
    } 
  
    // construct result by adding 1, 
    // msbPos times 
    int maxXOR = 0; 
    int two = 1; 
    while (msbPos--) 
    { 
        maxXOR += two; 
        two <<= 1; 
    } 
    cout<<maxXOR<<endl;
}