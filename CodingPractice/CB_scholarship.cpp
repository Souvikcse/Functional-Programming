#include<iostream>
typedef long long int ll;
using namespace std;

bool check(ll initial, ll num, ll req, ll give, ll total){
    return (initial+(total-num)*give)>=(num*req);
}
int main(){
    ll n, m, x, y;
    cin>>n>>m>>x>>y;
    
    ll ans;
    ll start = 0;
    ll end = n;
    while(start<=end){
        ll mid = (start+end)>>1;
        if(check(m, mid, x, y, n)){
            ans = mid;
            start = mid+1;
        }
        else  end = mid-1;
    }
    cout << ans <<endl;

}