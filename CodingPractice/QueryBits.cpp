#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
#define N 200010
using namespace std;

ll tree[N<<2], lazy[N<<2];
int mod = 1000000007;
ll fast_pow(ll a, ll p, int mod){
    ll res=1;
    while(p>0){
        if(p&1)
            res=(res*a)%mod;
        
        a=(a*a)%mod;
        p>>=1;
    }
    return res;
}
void lazy_up(int node, int st, int en){
    if(lazy[node]!=-1){
        tree[node]=(fast_pow(2, en-st+1, mod)-1)*lazy[node];
        if(st!=en){
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=-1;
    }
}
void updateRangeLazy(int st, int en, int qs, int qe, int val, int parent){
    lazy_up(parent, st, en);
    if(st>qe ||en<qs)
        return;
    
    /* Complete Overlap--- Just update the parent node and make lazy update for the two child nodes and return. No need to update the entire range */
    if(st>=qs && en<=qe){
        tree[parent]= (fast_pow(2, en-st+1, mod)-1)*val;
        if(st!=en){
            lazy[2*parent]=val;
            lazy[2*parent+1]=val;
        }
        return;
    }
    int mid= (st+en)>>1;
    updateRangeLazy(st, mid, qs, qe, val, 2*parent);
    updateRangeLazy(mid+1, en, qs, qe, val, 2*parent+1);
    tree[parent]= ((tree[2*parent]*fast_pow(2, en-mid, mod)%mod)+ tree[2*parent+1])%mod;
}
ll query(int st, int en, int qs, int qe, int parent){
    lazy_up(parent, st, en);
    if(st>qe || en<qs)
        return 0;
    if(st>=qs && en<=qe)
        return tree[parent];

    int mid= (st+en)>>1;
    ll ans1= query(st, mid, qs, qe, 2*parent);
    ll ans2= query(mid+1, en, qs, qe, 2*parent+1);

    ll ans= ((ans1*fast_pow(2, min(en, qe)-mid, mod))%mod + ans2)%mod;
    return ans;
}
int main(){
    int n, q;
    cin>>n>>q;
    
    memset(tree, 0, sizeof(tree));
    memset(lazy, -1, sizeof(lazy));

    int type, l, r;
    while(q--){
        cin>>type>>l>>r;
        if(type!=2){
            updateRangeLazy(0, n-1, l, r, type, 1);
        }
        else
            cout<<query(0, n-1, l, r, 1)<<"\n";
    }
}