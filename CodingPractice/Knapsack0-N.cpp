#include <iostream>
#include<cmath>
#include<unordered_set>
#define N 1000001
using namespace std;

int max_Profit(int *w, int *val, int i, int n, int cap, int *dp[]){
    if(i>=n || cap==0)   return 0;

    if(dp[i][cap]!=-1)
        return dp[i][cap];
    int ans = 0;
    if(cap>=w[i])
        ans = max(max_Profit(w, val, i, n, cap-w[i], dp)+val[i], max_Profit(w, val, i+1, n, cap, dp));
    else
        ans = max_Profit(w, val, i+1, n, cap, dp);

    dp[i][cap] = ans;
    return ans;
}
int main(){
    int n, w;
    cin>>n>>w;

    int weight[n];
    int val[n];
    for(int i=0;i<n;i++)     cin>>weight[i];
    for(int i=0;i<n;i++)     cin>>val[i];

    int **dp = (int**)calloc(n, sizeof(int*));
    for(int i=0;i<n;i++)
        dp[i] = (int*)calloc(w+1, sizeof(int));

    for(int i=0;i<n;i++)
        for(int j=0;j<=w;j++)
            dp[i][j]=-1;

    cout << max_Profit(weight, val, 0, n, w, dp);
}