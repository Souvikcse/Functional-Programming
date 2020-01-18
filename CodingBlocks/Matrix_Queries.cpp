#include<iostream>
using namespace std;

int range;
class Matrix{
    public:
    int mat[2][2];
};
void buildTree(Matrix* a, int ss, int se, Matrix* tree, int parent){
    if(ss==se){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++)
                tree[parent].mat[i][j] = a[ss].mat[i][j];
        }
        return;
    }
    int mid=(ss+se)/2;
    buildTree(a, ss, mid, tree, 2*parent);
    buildTree(a, mid+1, se, tree, 2*parent +1);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            int sum=0;
           for(int k=0;k<2;k++)  sum= (sum+ (tree[2*parent].mat[i][k]*tree[2*parent + 1].mat[k][j])%range)%range;

           tree[parent].mat[i][j]=sum; 
        }
    }
}
class Queries{
    public:
    int start, end;
};
int** query(Matrix* tree, int ss, int se, int qs, int qe, int parent){
    // No Overlap
    if(qs>se || qe<ss){
        int **ans = new int*[2];
        for(int i=0;i<2;i++)   ans[i]= new int[2];

        for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (i == j) 
					ans[i][j] = 1;
				else
                    ans[i][j]=0;
			}
		}
        return ans;
    }
    // Complete Overlap
    if(ss>=qs && se<=qe){
        int **ans = new int*[2];
        for(int i=0;i<2;i++)   ans[i]= new int[2];

        for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)  ans[i][j]= tree[parent].mat[i][j];
        }
        return ans;
    }
    int mid=(ss+se)/2;
    int** leftans= query(tree, ss, mid, qs, qe, 2*parent);
    int** rightans= query(tree, mid+1, se, qs, qe, 2*parent +1);
    
    int **ans = new int*[2];
    for(int i=0;i<2;i++)   ans[i]= new int[2];

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            int sum=0;
           for(int k=0;k<2;k++)  sum= (sum+ (leftans[i][k]*rightans[k][j])%range)%range;

           ans[i][j]=sum; 
        }
    }
    return ans;
}
int main(){
    int r, n, q;
    cin>>r>>n>>q;

    range=r;
    Matrix *a = new Matrix[n];
    for(int i=0;i<n;i++){
        cin>>a[i].mat[0][0]>>a[i].mat[0][1]>>a[i].mat[1][0]>>a[i].mat[1][1];
    }
    Matrix *tree = new Matrix[4*n + 1];
    buildTree(a, 0, n-1, tree, 1);

    Queries *que = new Queries[q];
    for(int i=0;i<q;i++){
        cin>>que[i].start>>que[i].end;
    }
    int **answer;
    for(int i=0;i<q;i++){
        answer = query(tree, 0, n-1, que[i].start -1, que[i].end -1, 1);
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++)  
                cout<<answer[i][j]<<" ";
            cout<<"\n";
        }
        cout<<"\n";
    }
}