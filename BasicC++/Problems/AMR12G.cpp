#include<bits/stdc++.h>
#define Size(a) (int)sizeof(a)/sizeof(a[0])
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
using namespace std;

char ar[52][52];
int findMin(int *ar, int len){
    int min=0;
    REP(1, len, 1){
        if(ar[i]<min)
            min=i;
    }
    return min;
}
int compute(int N, int M, int K){
    int *bulbslit=new int[N]{0};
    REP(0, N, 1){
        for (int j = 0; j < M; j++)
        {
            if(ar[i][j] == '*') bulbslit[i]++;
        }
    }
    sort(bulbslit, bulbslit+N);
    int idx=0;
    while(K>0 && idx<N && (M-bulbslit[idx])>bulbslit[idx]){
        bulbslit[idx]=M-bulbslit[idx];
        --K;
        ++idx;
    }
    if(K!=0 && K%2==1){
        int loc=findMin(bulbslit, N);
        bulbslit[loc]=M-bulbslit[loc];
    }
    int ans= 0;
    REP(0, N, 1){
        ans+=bulbslit[i];
    }
    delete[] bulbslit;
    bulbslit=NULL;
    return ans;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int N, M, K;
        cin>>N>>M>>K;
        REP(0, N, 1){
            for(int j=0;j<M;j++)
                cin>>ar[i][j];
        }
        cout<<compute(N, M, K)<<"\n";
    }
    
}