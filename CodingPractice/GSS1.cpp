#include<iostream>
#include<cmath>
#define N 50010
#define INT_MIN -221121
using namespace std;

class Node{
    public:
    int prefixSum;
    int suffixSum;
    int total;
    int maxSum;
};
int a[50010];
Node tree[4*N];
void buildTree(int st, int en, int parent){
    if(st==en){
        tree[parent].total=a[st];
        tree[parent].prefixSum=a[st];
        tree[parent].suffixSum=a[st];
        tree[parent].maxSum=a[st];
        return;
    }
    int mid=(st+en)>>1;
    buildTree(st, mid, 2*parent);
    buildTree(mid+1, en, 2*parent+1);

    tree[parent].prefixSum= max(tree[2*parent].prefixSum, tree[2*parent].total+tree[2*parent+1].prefixSum);
    tree[parent].suffixSum= max(tree[2*parent+1].suffixSum, tree[2*parent+1].total+tree[2*parent].suffixSum);
    tree[parent].total= tree[2*parent].total+ tree[2*parent+1].total;
    tree[parent].maxSum= max(tree[2*parent].maxSum, max(tree[2*parent+1].maxSum, tree[2*parent].suffixSum+tree[2*parent+1].prefixSum));
}
Node maxSumQuery(int idx,int ss,int se,int qs,int qe){

        if(ss>=qs&&se<=qe)
            {  return tree[idx];}
         if(qs>se||qe<ss){
             Node res;
             res.maxSum= INT_MIN;
             res.prefixSum=INT_MIN;
             res.suffixSum=INT_MIN;
             res.total=INT_MIN;

             return res;
         }

        int mid = (ss+se)>>1;

        Node left = maxSumQuery(2*idx,ss,mid,qs,qe);
        Node right = maxSumQuery(2*idx+1,mid+1,se,qs,qe);
        Node temp;

        temp.prefixSum = max(left.prefixSum,left.total+right.prefixSum);
        temp.suffixSum = max(right.suffixSum,right.total+left.suffixSum);
        temp.total = left.total + right.total;
        temp.maxSum   = max(left.suffixSum+right.prefixSum,max(left.maxSum,right.maxSum));

        return temp;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);

    buildTree(0, n-1, 1);
    int q, l, r;
    scanf("%d", &q);
    for(int i=0;i<q;i++){
        scanf("%d %d", &l, &r);
        printf("%d\n", maxSumQuery(1, 0, n-1, l-1, r-1).maxSum);
    }
}