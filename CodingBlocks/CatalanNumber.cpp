#include<iostream>
typedef long long ll;
using namespace std;

ll G[101];
ll Catalan(int n){
    G[0]=G[1]=1;

    for(int i=2;i<=n;i++){
        G[i]=0;
        for(int j=1;j<=i;j++){
            G[i]+=G[j-1]*G[i-j];
        }
    }
    return G[n];
}
int main(){
    int n;
    cin>>n;
    cout<<Catalan(n)<<"\n";
}