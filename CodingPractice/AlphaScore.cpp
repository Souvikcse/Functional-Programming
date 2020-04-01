#include<iostream>
typedef long long int ll;
#define N 1e9
using namespace std;

int mod = 1e9+7;
int count = 0;
void merge(ll *a, int l, int mid, int r){
    int n1 = mid-l+1;
    int n2 = r-mid;

    int k=0;
    ll left[n1], right[n2];
    for(int i=l;i<=mid;i++)
        left[k++] = a[i];
    
    k=0;
    for(int i=mid+1;i<=r;i++)
        right[k++] = a[i];

    int p=0, q=0;
    k=l;
    while(p<n1 && q<n2){
        if(left[p]<right[q]){
            count = (count+(left[p]*(n2-q))%mod)%mod;
            a[k++] = left[p++];
        }
        else{
            a[k++] = right[q++];
        }
    }
    while(p<n1){
        a[k++] = left[p++];
    }
    while(q<n2){
        a[k++] = right[q++];
    }
}
void mergesort(ll *a, int low, int hi){
    if(low<hi){
        int mid = (low+hi)>>1;

        mergesort(a, low, mid);
        mergesort(a, mid+1, hi);
        merge(a, low, mid, hi);
    }
}
int main(){
	int t;
	cin>>t;
    while(t--){
    int n;
    cin>>n;
    ll *a = (ll*)calloc(n, sizeof(ll));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergesort(a, 0, n-1);
    //  for(int i=0;i<n;i++){
    //     cout<< a[i] << " ";
    // }
    cout << count << "\n";
    }
}