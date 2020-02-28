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
        int sum= n*min(a[0], b[0]);
        cout<<sum<<"\n";
    }
}