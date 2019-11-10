#include <iostream>
#include<cstring>
#include<cmath>
 
using namespace std;
 
int dp[101];
int Ways(string s, int i, int n, int m, int a, int out){
    if(i<0){
        if(out%m == 0)
            return 1;
        else
            return 0;
    }
    if(dp[i]!=-1)
        return dp[i];
 
    int ans;
    if(s[i]=='1'){
        ans=Ways(s, i-1, n, m, a+1, out+pow(2, a));
    }
    if(s[i]=='0')
        ans=Ways(s, i-1, n, m, a+1, out);
    if(s[i]=='-'){
        ans=Ways(s, i-1, n, m, a+1, out)+Ways(s, i-1, n, m, a+1, out+pow(2, a));
    }
    dp[i]=ans;
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        memset(dp, -1, sizeof(dp));
        cout<<Ways(s, n-1, n, m, 0, 0)<<endl;
    }
}
