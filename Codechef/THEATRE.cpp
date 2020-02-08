#include<iostream>
#include<cstring>
typedef long long ll;
using namespace std;

int freq[4][4];
int cost[4];

ll MaxProfit(int movie,int slot_mask, int c_mask){
    if(movie >=4)
        return 0;
    
    ll ans=0;
    for(int i=0;i<4;i++){
        if((slot_mask&(1<<i))==0){
        for(int j=0;j<4;j++){
            if((c_mask&(1<<j))==0)
                ans= max(ans, MaxProfit(movie+1, slot_mask|(1<<i), c_mask|(1<<j))+ cost[j]*freq[movie][i]);
        }
    } 
    }
    return ans;
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
        string str;
        int x;
        int mask=0;
        for(int i=0;i<n;i++){
            cin>>str>>x;
            int mov= str.compare("A");
            mask|= 1<<(mov);
            if(x==12)    freq[mov][0]++;
            else if(x==3)  freq[mov][1]++;
            else  if(x==6)   freq[mov][2]++;
            else  freq[mov][3]++;
        }
        int c= __builtin_popcount(mask);
        ll profit=0;
        if(n>0)    profit= MaxProfit(0, 0, 0);

        //cout<<freq[3][0]<<"\n";
        profit-= ((4-c)*100);
        //cout<<c<<" "<<profit<<"\n";
        cout<<profit<<"\n";
        total_profit+=profit;
    }
    cout<<total_profit<<endl;
}