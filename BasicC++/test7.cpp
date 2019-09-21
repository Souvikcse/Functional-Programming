#include<bits/stdc++.h>
typedef long long ll;
#define Size(a) (int)sizeof(a)/sizeof(a[0])
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
using namespace std;

int X[100001], Y[100001];
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        REP(0, m, 1){
            cin>>X[i];
        }
        REP(0, n, 1){
            cin>>Y[i];
        }
        sort(Y, Y+n);
        int ans=0;

        REP(0, m, 1){
            int start=0;
            int end=n-1;
            while(start<=end ){
                int mid=(start+end)/2;
                if (pow(X[i], Y[mid]) <= pow(Y[mid], X[i]) && pow(X[i], Y[mid+1]) > pow(Y[mid+1], X[i]))
                {
                  ans+= n-mid-1;
                  break;
                }
                else if(pow(X[i], Y[mid]) > pow(Y[mid], X[i])){
                    end=mid-1;
                }
                else 
                    start=mid+1;
            }
            cout<<X[i]<<" ";
        }
        cout<<ans;
        cout<<"\n";
    }
}