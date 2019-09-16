#include<bits/stdc++.h>
typedef long long ll;
#define Size(a) (int)sizeof(a)/sizeof(a[0])
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
};
Node* insert(Node* root, int data){
    if(root == NULL){
        root = new Node();
        root->data = data;
        return root;
    }
    if(root->data > data)
       root->left= insert(root->left, data);

    if(root->data < data)
       root->right= insert(root->right, data);

    return root;
}
Node* buildTree(int ar[], int len){
    Node* root = new Node();
    root->data = ar[0];
    for(int i=1;i<len; i++){
        insert(root, ar[i]);
    }
    return root;
}
// void print(Node* root){
//     if(root == NULL)
//         return;

//     print(root->left);
//     cout<<root->data<<" ";
//     print(root->right);
// }
int findLCA(Node* root, int n1, int n2){
    
    if(root->data >= n1 && root->data <= n2)
        return root->data;
    
    if(root->data > n1 && root->data > n2)
        return findLCA(root->left, n1, n2);

    if(root->data < n1 && root->data <n2)
        return findLCA(root->right, n1, n2);
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int* a = new int[n];
        for(int i=0;i<n;i++)
            cin>>a[i];

        int n1,n2;
        cin>> n1>>n2;
        Node* root = buildTree(a, n);
       // print(root);
        int ans = findLCA(root, n1, n2);
        cout<<ans<<"\n";
        delete [] a;
    } 
}