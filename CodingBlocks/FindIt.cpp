#include<bits/stdc++.h>
using namespace std;

int a[100002], Que[100002];
int cnt[100002], ans[100002];
void sieve(int n, int N){
    memset(cnt, 0, (N+2)*sizeof(cnt[0]));
    memset(ans, 0, (N+2)*sizeof(ans[0]));
    for(int i=0;i<N+1;i++)
        cnt[a[i]]++;

    for(int i=2;i<N+1;i++)
        for(int j=i;j<N+1;j+=i)
            ans[i]+=cnt[j];
}
int multiplesof(int num){
    return ans[num];
}
int main(){
    int n;
    cin>>n;
    int maxn=a[0];
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxn=max(a[i], maxn);
    }
    sieve(n, maxn);
    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++)
       {
           cin>>Que[i];
       } 
    for(int i=0;i<Q;i++)
        cout<<multiplesof(Que[i])<<endl;
}