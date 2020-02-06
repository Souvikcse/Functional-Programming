#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;

int a[100001];
class Queries{
    public:
    int l, r, k;
};
Queries que[100001];
void buildTree(int **tree, int ss, int se, int parent){
    if(ss==se){
        tree[parent] = new int[1];
        tree[parent][0]=a[ss];
        return;
    }
    int mid = (ss+se)/2;
    buildTree(tree, ss, mid, 2*parent);
    buildTree(tree, mid+1, se, 2*parent + 1);

    //Pushing left subtree and right subtree elements in sorted fashion into parent node
    tree[parent] = new int[se-ss+1];
    merge(tree[2*parent], tree[2*parent]+(mid-ss+1), tree[2*parent+1], tree[2*parent+1]+(se-mid), tree[parent]);
}
int query(int **tree, int ss, int se, int qs, int qe, int val, int parent){
    // No Overlap
    if(qe<ss || qs>se)
        return 0;
    
    // Complete Overlap
    if(ss>=qs && se<=qe){
        int lb = lower_bound(tree[parent], tree[parent]+(se-ss+1), val) - tree[parent];
        return (se-ss+1)-lb;
    }
    int mid = (ss+se)/2;
    int ans1= query(tree, ss, mid, qs, qe, val, 2*parent);
    int ans2= query(tree, mid+1, se, qs, qe, val, 2*parent + 1);
    return ans1+ans2;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];

    int q;
    cin>>q;
    for(int i=0;i<q;i++)
        cin>>que[i].l>>que[i].r>>que[i].k;

    int **tree = new int*[4*n+1];
    buildTree(tree, 0, n-1, 1);

    for(int i=0;i<q;i++){
        cout<<query(tree, 0, n-1, que[i].l - 1, que[i].r - 1, que[i].k, 1)<<"\n";
    }
}