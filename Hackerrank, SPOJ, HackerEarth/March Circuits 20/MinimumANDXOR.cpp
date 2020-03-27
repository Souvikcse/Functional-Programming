#include<iostream>
#include<algorithm>
using namespace std;

int a[1000001];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a, a+n);
        int ans = INT32_MAX;
        for(int i=0;i<(n-1);i++){
            ans = min(ans, a[i]^a[i+1]);
        }
        cout<< ans << endl;
    }
}