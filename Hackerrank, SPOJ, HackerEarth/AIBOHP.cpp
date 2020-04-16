#include<iostream>
#include<cstring>
using namespace std;

int dp[6101][6101];
char s[6109];
int min_insert(int lo, int hi){
    if(lo>=hi)    return 0;
    if(dp[lo][hi]!=-1)  return dp[lo][hi];

    int ans;
    if(s[lo]==s[hi])   ans = min_insert(lo+1, hi-1);
    else{
        ans = min(min_insert(lo+1, hi), min_insert(lo, hi-1))+1;
    }
    dp[lo][hi] = ans;
    return ans;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        
        int n = strlen(s);
        memset(dp, -1, sizeof(dp));
        printf("%d\n", min_insert(0, n-1));
    }
}