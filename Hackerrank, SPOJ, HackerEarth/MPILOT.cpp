#include<iostream>
//typedef long long int ll;
using namespace std;

int min_amount(pair<int, int> *a, int i, int captain, int n, int **dp){
    if(i<0){
        return 0LL;
    }
    if(dp[i][captain]!=-1)
        return dp[i][captain];

    int ans = 0;
    if(captain==(n-1-i-captain))
        ans = min_amount(a, i-1, captain+1, n, dp)+a[i].first;
    else if(captain==(n/2))
        ans = min_amount(a, i-1 ,captain, n, dp)+a[i].second;
    else
        ans = min(min_amount(a, i-1, captain+1, n, dp)+a[i].first, min_amount(a, i-1, captain, n, dp)+a[i].second);
    
    dp[i][captain] = ans;
    return ans;
}
int main(){
    int n;
    scanf("%d", &n);
    pair<int, int> *a = new pair<int, int>[n];
    for(int i=0;i<n;i++){
        scanf("%d %d", &a[i].first, &a[i].second);
    }
    int **dp = (int**)calloc(n,sizeof(int *)); 
    for (int i=0; i<n; i++) 
         dp[i] = (int*)calloc((n/2)+1, sizeof(int)); 

    for(int i=0;i<n;i++)
        for(int j=0;j<(n/2)+1;j++)
            dp[i][j]=-1;

    printf("%d \n", min_amount(a, n-1, 0, n, dp));
}