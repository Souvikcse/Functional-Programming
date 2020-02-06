#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int a[101], dp[101][101];
int color(int i, int j){
    int ans=0;
    for(int t=i;t<=j;t++){
        ans=(ans+a[t])%100;
    }
    return ans;
}
int smokegenerated(int start, int end){
    if(start==end)
        return 0;
    if(dp[start][end]!=-1)
        return dp[start][end];

    int ans=INT_MAX;
    for(int k=start;k<end;k++){
        ans= min(ans, smokegenerated(start, k)+smokegenerated(k+1, end)+ (color(start, k)*color(k+1, end)));
    }
    dp[start][end]=ans;
    return ans;
}
int main(){
    int n;
    while (scanf("%d", &n)!=EOF) {
        for(int i=0;i<n;i++){
            cin>>a[i];
        }   
        for(int i=0;i<101;i++)
            for(int j=0;j<101;j++)
                dp[i][j]=-1;

        cout<<smokegenerated(0, n-1)<<endl;
    }
}