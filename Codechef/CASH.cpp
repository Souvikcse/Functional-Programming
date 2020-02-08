#include<iostream>
#include<cmath>
typedef long long ll;
using namespace std;

int a[100001];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        int ans= sum%k;
        cout<<ans<<"\n";
    }
}