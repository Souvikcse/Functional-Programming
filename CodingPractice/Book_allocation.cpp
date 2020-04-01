#include<iostream>
typedef long long int ll;
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    ll a[n];
    ll end = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        end += a[i];
    }
    ll ans;
    ll start = a[0];
    while(start<=end){
        ll mid = (start+end)>>1;
        ll pages = 0, k = 1;
        int i;
        for(i=0;i<n;i++){
            if((pages+a[i])<=mid)  pages+= a[i];
            else{
                if(a[i]>mid)  break;
                pages = a[i];
                k++;
            }
        }
        if(k<=m && i==n){
            ans = mid;
            end = mid-1;
        }
        else  start = mid+1;
    }
    cout << ans << endl;
}