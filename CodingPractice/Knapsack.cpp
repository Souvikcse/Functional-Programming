#include<iostream>
using namespace std;

int main(){
    int n, sum;
    cin>>n>>sum;

    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int val[n];
    for(int i=0;i<n;i++)
        cin>>val[i];

    int dp[2][sum+1];
    int k=0;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j==0 || i==0)
                dp[k][j] = 0;
            else if(a[i-1]<=j){
                dp[k][j] = max(dp[k^1][j-a[i-1]]+val[i-1], dp[k^1][j]);
            }
            else{
                dp[k][j] = dp[k^1][j];
            }
        }
        k^=1;
    }
    cout<<dp[k^1][sum]<<endl;
}