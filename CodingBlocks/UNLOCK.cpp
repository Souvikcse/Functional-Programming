#include<bits/stdc++.h>
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
typedef long long ll;
using namespace std;

int ar[100001];
int pos[100001];
int main(){
    int N, K;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>ar[i];
    }
    REP(0, N, 1){
        pos[ar[i]]=i;
    }
    for(int i=0;i< N && K; i++){
       if(pos[N-i]!=i){
           int temp=pos[N-i];
            pos[ar[i]] = pos[N-i]; 
            pos[N-i] = i; 
            swap(ar[i], ar[temp]);
           --K;
       }
    }
    REP(0, N, 1){
        cout<<ar[i]<<" ";
    }
}