#include<iostream>
#include<vector>
typedef long long ll;
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
#define mod 1000000007
using namespace std;

// vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B){
//     vector<vector<ll>> res(3, vector<ll>(3));

//     for(int i=0;i<3;i++){
//         for(int j=0;j<3;j++){
//             for(int x=0;x<3;x++)
//                 res[i][j]= (res[i][j] + (A[i][x]*B[x][j])%MOD)%MOD;
//         }
//     }
//     return res;
// }
// vector<vector<ll>> power(vector<vector<ll>> T, int pow){
//     if(pow==1)
//         return T;

//     if(pow&1)
//         return multiply(T, power(T, pow-1));
//     else{
//         vector<vector<ll>> X=power(T, pow/2);
//         return multiply(X, X);
//     }
// }
// ll compute(ll n){
//     if(n==1){
//         return 1LL;
//     }
//     if(n==2){
//         return 6LL;
//     }
//     vector<vector<ll>> T(3, vector<ll>(3));
//     T[0][0]=0; T[0][1]=1; T[0][2]=0;
//     T[1][0]=-1; T[1][1]=2; T[1][2]=1;
//     T[2][0]=0; T[2][1]=0; T[2][2]=1;

//     vector<ll> F1(3);
//     F1[0]=1, F1[1]=6, F1[2]=4;

//     T=power(T, n-1);

//      ll ans=0;
//     for(int i=0;i<3;i++){
//         ans=(ans+(T[0][i]*F1[i])%MOD)%MOD;
//     }

//     return ans;
// }
int main(){
    int t;
    cin>>t;
    while (t--)
    {
    ll n;
    cin>>n;
    ll a=n;
    ll b=(2*n)-1;
    ll ans=((a % mod) * (b % mod)) % mod;
    cout<<ans<<"\n";
    }
}