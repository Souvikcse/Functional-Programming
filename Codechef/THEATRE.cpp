#include<iostream>
#include<cstring>
typedef long long ll;
using namespace std;

int freq[4][4];
int cost[4];
bool check[4];

int MaxProfit(){
    int sum = 0, slot = 0;
    int ans = 0;
    for(int i=0;i<4;i++){
        slot|= 1<<i;
        for(int j=0;j<4;j++){
            if((slot&(1<<j))==0){
                slot|= 1<<j;
                for(int k=0;k<4;k++){
                    if((slot&(1<<k))==0){
                        slot|= 1<<k;
                        for(int l=0;l<4;l++){
                            if((slot&(1<<l))==0){
                                slot|= 1<<l;

                            }
                        }
                    }
                }
            }
        }
        slot = 0;
    }
}
int main(){
    cost[0]=100, cost[1]=75, cost[2]=50, cost[3]=25;
    int t;
    cin>>t;
    ll total_profit=0;
    while(t--){
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                freq[i][j]=0;

        int n;
        cin>>n;
        char m; int t;
        int profit = 0;
        for(int i=0;i<n;i++){
            cin>>m>>t;
            t = t!=12? t+12:t;
            freq[m-'A'][(t-12)/3]++;
        }
        memset(check, false, sizeof(check));
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if(freq[i][j])   check[i] = true;

        for(int i=0;i<4;i++)
            if(!check[i])  profit -= 100;

        profit += MaxProfit();
        cout<<profit<<"\n";
    }
    cout<<total_profit<<endl;
}