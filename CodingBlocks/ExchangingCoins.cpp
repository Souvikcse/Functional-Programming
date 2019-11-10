#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

unordered_map<ll, ll> umap;
ll solve(ll num){
    if(num==0)
        return 0;
    if(umap.find(num)!=umap.end())
        return umap[num];
    
    ll ans=max(num, solve(num/2)+solve(num/3)+solve(num/4));
    umap[num]=ans;
    return ans;
}
int main(){
    ll n;
    cin>>n;
    cout<<solve(n)<<endl;
}