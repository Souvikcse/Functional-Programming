#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int a[10001], b[10001];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a, a+n);
        sort(b, b+n);
        long long int sum=0;
        for(int i=n-1;i>=0;i--){
            sum+= min(a[i], b[i]);
        }
        cout<<sum<<"\n";
    }
}