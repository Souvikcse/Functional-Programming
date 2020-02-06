#include<iostream>
#include<algorithm>
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
using namespace std;

int ar1[1001], ar2[1001];
int ar[2001];
int merge(int n){
    int i=0, j=0, k=0;
    while(i<n && j<n){
        if(ar1[i]<=ar2[j]){
            ar[k]=ar1[i];
            i++;
        }
        else{
            ar[k]=ar2[j];
            j++;
        }
        k++;
    }
    while (i<n)
    {
        ar[k]=ar1[i];
        i++;
        k++;
    }
    while (j<n)
    {
        ar[k]=ar2[j];
        j++;
        k++;
    }
    int answer=ar[n-1];
    return answer;
}
int main(){
    int n;
    cin>>n;
    REP(0, n, 1){
        cin>>ar1[i];
    }
    REP(0, n, 1){
        cin>>ar2[i];
    }
    int ans=merge(n);
    cout<<ans;
}