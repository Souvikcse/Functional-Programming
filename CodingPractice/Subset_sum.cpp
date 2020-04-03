#include<iostream>
#define rep(a, b, c) for(int i=a; i<b;i+=c)
using namespace std;

int main(){
    int n, sum;
    cin>>n>>sum;
    int a[n+1];
    rep(1, n+1, 1){
        cin>>a[i];
    }
    bool dp[2][sum+1];
    int k = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j==0)
                dp[k][j] = 1;
            else if(i==0)
                dp[k][j] = 0;
            else if(j>=a[i]){
                dp[k][j] = dp[k^1][j-a[i]] || dp[k^1][j]; 
            }
        }
        k^=1;
    }
    dp[k^1][sum]==true? cout<<"Yes":cout<<"No";
    cout<<endl;
}