#include<bits/stdc++.h>
typedef long long ll;
#define Size(a) (int)sizeof(a)/sizeof(a[0])
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int left=m%((n*(n+1))/2);
        REP(1, n+1, 1){
            if(left < i)
              break;

            left-=i;
        }
        cout<<left<<"\n";
    }
}