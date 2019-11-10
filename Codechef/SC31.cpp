#include<iostream>
#include<cstring>
typedef long long ll;
#define mod 1000000007
using namespace std;

int s[100001], dp[100001];
int countSetBits(int num){
    int c=0;
    while(num){
        if(num&1)
            c++;
        num>>=1;
    }
    return c;
}
// int maxSetBits(int i, int lim){
//     memset(dp, 0, sizeof(dp));
//     dp[0]=countSetBits(s[0]);
//     for(int i=1;i<lim;i++){
//     for(int j=0;j<i;j++){
        
//        // cout<<ans<<"-> ";
//         dp[i]=max(dp[i], countSetBits(dp[i]^s[j]));
//         //s[j]=num;
//         //ans=max(ans, maxSetBits(i+1, lim));
//         //cout<<ans<<" ";
//     } 
//     }
//     return dp[n];
// }
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            string str;
            cin>>str;
            s[i]=stoi(str, 0, 2);
        }
        int res=0;
       for(int i=0;i<n;i++){
           res=res^s[i];
       }
       cout<<countSetBits(res)<<endl;
    }
}