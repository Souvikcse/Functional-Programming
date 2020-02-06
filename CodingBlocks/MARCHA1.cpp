#include<iostream>
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
typedef long long ll;
using namespace std;

int a[21];
bool check_combination(int mask, int k){
    int sum=0;
    int i=0;
    while(mask >0){
        if((mask & 1)!=0){
            sum+=a[i];
        }
        i++;
        mask= mask>>1;
    }
    if(sum == k)
        return true;
    else
        return false;
}
bool is_Sum_Possible(int n, int sum){
    int range = (1<<n);
    REP(0, range, 1){
        bool status= check_combination(i, sum);
        if(status)
          return true;
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while (t--){
        int n, K;
        cin>>n>>K;
        REP(0, n, 1){
            cin>>a[i];
        }
        is_Sum_Possible(n, K)?cout<<"Yes":cout<<"No";
        cout<<"\n";
    }
}