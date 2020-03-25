#include<iostream>
#include<cstring>
#include<algorithm>
typedef long long ll;
using namespace std;

int freq[4][4];
int cost[4];

int MaxProfit(){
    string slot = "0123";
    int f[4];
    int ans = -1e9;
    for(int i=0;i<24;i++){
        int sum = 0;
        for(int i=0;i<4;i++){
            f[i] = freq[i][slot[i]-'0'];        //Assign movie A,B,C,D to slot[i] p.m.
        }
        sort(f, f+4);
        for(int i=0;i<4;i++){
            if(f[i]==0)
                sum -= 100;
            else
                sum += (i+1)*25*f[i];
        }
        ans = max(ans, sum);
        next_permutation(slot.begin(), slot.end());
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
        string s; int ti;
        int profit = 0;
        for(int i=0;i<n;i++){
            cin>>s>>ti;
            char m = s[0];
            ti = ti!=12? ti+12:ti+0;
            freq[m-'A'][(ti-12)/3]++;
        }
        profit += MaxProfit();
        cout<<profit<<"\n";
        total_profit += profit;
    }
    cout<<total_profit<<endl;
}