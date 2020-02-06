#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int mod = 1000000007;
class Queries{
    public:
    int type, l, r;
};
Queries que[200001];
void updateRange(int *tree, int ss, int se, int qs, int qe, int val, int parent){
    if(qe<ss || qs>se)
        return;

    // Complete Overlap
    if(ss==se){
        tree[parent]= val;
        return;
    }
    int mid=(se+ss)/2;
    updateRange(tree, ss, mid, qs, qe, val, 2*parent);
    updateRange(tree, mid+1, se, qs, qe, val, 2*parent+1);
     
}
int main(){
    int n, q;
    cin>>n>>q;

    for(int i=0;i<q;i++)
        cin>>que[i].type>>que[i].l>>que[i].r;

    int *tree = (int*)calloc(4*n+1, sizeof(int));

}