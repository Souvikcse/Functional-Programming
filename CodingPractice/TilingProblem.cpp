#include<iostream>
#include<cstring>
typedef long long ll;
#define MOD 1000000007
using namespace std;

ll compute(int n, int m, ll *dp){
    if(n==0)
        return 1;

    if(dp[n]!=-1){
        return dp[n];
    }
    ll ans1=compute(n-1, m, dp);
    ll ans2=0;
    if(n>=m){
         ans2+=compute(n-m, m, dp);
    }
    dp[n]= ans1+ans2;
    return dp[n];
}
ll dp[100001];
int main(){
    int t;
    cin>>t;
    while (t--)
    {
       int n,m;
       cin>>n>>m;
        memset(dp, -1, (n+1)*sizeof(ll));
       cout<<compute(n, m, dp)<<endl;
    }
    
}