#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int k;
    cin>>k;
    int n;
    cin>>n;
    int a[n];
    int end=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        end+=a[i];
    }
    //sort(a, a+n);
    int ans;
    int start = 0;
    while(start<=end){
        int mid=(start+end)>>1;
        int time=mid;
        int count = 1;
        int i;
        for( i=0;i<n;i++){
            if(a[i]<=time)   time -= a[i];
            else{
                if(a[i]>mid)   break;
                count++;
                if(count > k)   break;
                time = mid-a[i];
            }  
        }
        if(i!=n)   start=mid+1;
        else{
            ans = mid;
            end = mid-1;
        }
    }
    cout << ans << endl;
}