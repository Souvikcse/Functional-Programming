#include<iostream>
#include<vector>
typedef long long ll;
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
#define MOD 1000000000
using namespace std;

vector<ll> b, c;
int k;
vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B){
    vector<vector<ll>> C(k+1, vector<ll>(k+1));

    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int x=1;x<=k;x++){
                C[i][j]= (C[i][j] + (A[i][x]*B[x][j])%MOD)%MOD;
            }
        }
    }
    return C;
}
vector<vector<ll>> power(vector<vector<ll>> T, int pow){
    if(pow==1)
        return T;
    
   if(pow&1){
        return multiply(T, power(T,pow-1));
    }
    else{
        vector<vector<ll> > X = power(T,pow/2);
        return multiply(X,X);
    }
}
ll compute(int n){
    //if n less than k return f(n)
    if(n<=k){
        return b[n-1];
    }
    //else use matrix exponentiation
    //F1 matrix with indexing from 1
    vector<ll> F1(k+1);
    for(int i=1;i<=k;i++)
        F1[i]=b[i-1];

    //Transformation matrix indexing 1 theke
    vector<vector<ll>> T(k+1, vector<ll>(k+1));

    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            if(i<k){
                if(j==i+1)
                    T[i][j]=1;
                else
                    T[i][j]=0;

                continue;
            }
            T[i][j]=c[k-j];
        }
    }
    //Calculate T^(n-1)
    T=power(T, n-1);

    //Compute F(n) by T^n-1 * F(1)
    ll ans=0;
    for(int i=1;i<=k;i++){
        ans=(ans+(T[1][i]*F1[i])%MOD)%MOD;
    }

    return ans;
}
int main(){
    int C;
    cin>>C;
    while(C--){
        int n;
        cin>>k;
        ll num;
        REP(0, k, 1){
            cin>>num;
            b.push_back(num);
        }
        REP(0, k, 1){
            cin>>num;
            c.push_back(num);
        }
        cin>>n;
        cout<<compute(n)<<"\n";
        b.clear();
        c.clear();
    }
}