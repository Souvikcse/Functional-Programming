#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

int a[100001];
class Queries{
    public:
    int type, start, end;
};
Queries que[100001];
void buildTree(int ss, int se, int* tree, int parent){
    if(ss==se){
        tree[parent]=a[ss];
        return;
    }
    int mid=(ss+se)/2;
    buildTree(ss, mid, tree, 2*parent);
    buildTree(mid+1, se, tree, 2*parent + 1);
    tree[parent]=min(tree[2*parent], tree[2*parent + 1]);
}
void updateTree(int *tree, int ss, int se, int i, int val, int parent){
    // No Overlap
    if(i<ss || i>se)
        return;

    if(ss==se){
        tree[parent] = val;
        return;
    }
    int mid=(ss+se)/2;
    updateTree(tree, ss, mid, i, val, 2*parent);
    updateTree(tree, mid+1, se, i, val, 2*parent + 1);
    tree[parent] = min(tree[2*parent], tree[2*parent + 1]);
}
int query(int *tree, int ss, int se, int qs, int qe, int parent){
    // No Overlap
    if(qs>se || qe<ss)
        return INT_MAX;

    if(ss>=qs && se<=qe){
        return tree[parent];
    }
    int mid=(ss+se)/2;
    int left=query(tree, ss, mid, qs, qe, 2*parent);
    int right= query(tree, mid+1, se, qs, qe, 2*parent +1);
    return min(left, right);
}
int main(){
    int n, q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    for(int i=0;i<q;i++){
        cin>>que[i].type>>que[i].start>>que[i].end;
    }
    int *tree = new int[4*n + 1];
    buildTree(0, n-1, tree, 1);
    for(int i=0;i<q;i++){
        if(que[i].type == 2)
            updateTree(tree, 0, n-1, que[i].start - 1, que[i].end, 1);
        else
            cout<<query(tree, 0, n-1, que[i].start - 1, que[i].end - 1, 1)<<"\n";
    }
}