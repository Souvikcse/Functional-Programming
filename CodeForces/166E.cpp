#include<iostream>
using namespace std;

int mod = 1000000007;
int main(){
    int n;
    scanf("%d", &n);
    
    int **dp = (int**)calloc(4, sizeof(int*));
    for(int i=0;i<4;i++){
        dp[i] = (int*)calloc(n+1, sizeof(int));
    }
    dp[1][1] = dp[2][1] = dp[3][1] = 1;
    int prev_sum = 3;
    int sum;
    for(int i=2;i<=n;i++){
        sum = 0;
        for(int j=0;j<4;j++){
            dp[j][i] = (prev_sum - dp[j][i-1] + mod)%mod;
            sum = (sum + dp[j][i])%mod;
        }
        prev_sum = sum;
    }
    printf("%d", dp[0][n]);
}