#include<iostream>
#include<algorithm>
typedef long long int ll;
#define N 20001
using namespace std;

class stop{
    public:
    char type;
    int index;
    ll req;
    ll popu;
};
stop ar[N];
bool compare(stop a, stop b){
    if(a.index==b.index){
        return a.type=='C';
    }
    return a.index<b.index;
}
bool check(ll count, int n){
    for(int i=0;i<n;i++){
        if(ar[i].type=='B'){
            if(count<=ar[i].req)    return 0;
            count -= ar[i].req;
        }
        else{
            if(count>=ar[i].req)    count += ar[i].popu;
        }
    }
    return (count>0);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, b;
        cin>>x>>b;
        int i=0;
        for(;i<b;i++){
            ar[i].type='B';
            cin>>ar[i].index>>ar[i].req;
        }
        int c;
        cin>>c;
        for(int k=0;k<c;k++){
            ar[i].type='C';
            cin>>ar[i].index>>ar[i].req>>ar[i].popu;
            i++;
        }
        sort(ar, ar+b+c, compare);
        ll st = 0, en = 1e18;
        ll mid;
        ll ans = 1;
        while(st<=en){
            mid = (st+en)>>1;
            if(check(mid, b+c)){
                ans = mid;
                en = mid-1;
            }
            else   st = mid+1;
        }
        cout << ans << "\n";
    }
}