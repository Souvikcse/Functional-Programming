#include<iostream>
#include<cmath>
#include<cstring>
#include<unordered_set>
using namespace std;

int n, m;
bool is_Valid(int i, int j){
    if(i>=0 && i<n && j>=0 && j<m)
        return true;

    return false;
}
int *count;
void solve(int **mat, int i, int j, bool **visited, int **color, int val){
    if(is_Valid(i, j) && mat[i][j]==1 && !visited[i][j]){
        visited[i][j]=true;
        color[i][j]=val;
        count[val]++;
        solve(mat, i, j+1, visited, color, val);
        solve(mat, i+1, j, visited, color, val);
        solve(mat, i-1, j, visited, color, val);
        solve(mat, i, j-1, visited, color, val);
    }
}
int solve_pond(int **mat, bool **visited){
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            visited[i][j]=false;

    int **color= (int**)calloc(n, sizeof(int*));
    for(int i=0;i<m;i++)
        color[i]= (int*)calloc(m, sizeof(int));
    int col=1;
    memset(count, 0, sizeof(count));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1){
                solve(mat, i, j, visited, color, col);
                col++;
            }
        }
    }
    int **size= (int**)calloc(n, sizeof(int*));
    for(int i=0;i<m;i++)
        size[i]= (int*)calloc(m, sizeof(int));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            size[i][j]=count[color[i][j]];
        }
    }
    unordered_set<int> uset;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(color[i][j]==0){
                int res=1;
                if(is_Valid(i+1, j) && uset.find(color[i+1][j])==uset.end()) {
                    res+=size[i+1][j];
                    uset.insert(color[i+1][j]);}
                if(is_Valid(i, j+1) && uset.find(color[i][j+1])==uset.end())  {
                    res+=size[i][j+1];
                    uset.insert(color[i][j+1]);}
                if(is_Valid(i-1, j) && uset.find(color[i-1][j])==uset.end()) {
                    res+=size[i-1][j];
                    uset.insert(color[i-1][j]);}
                if(is_Valid(i, j-1) && uset.find(color[i][j-1])==uset.end()) { 
                    res+=size[i][j-1];
                    uset.insert(color[i][j-1]);}
                ans=max(ans, res);
                uset.clear();
            }
        }
    } 
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<color[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return ans;
}
int main(){
    cin>>n>>m;
    count= (int*)calloc(n*m+1, sizeof(int));
    int **mat= (int**)calloc(n, sizeof(int*));
    for(int i=0;i<m;i++)
        mat[i]= (int*)calloc(m, sizeof(int));

    bool **visited= (bool**)calloc(n, sizeof(bool*));
    for(int i=0;i<m;i++)
        visited[i]= (bool*)calloc(m, sizeof(bool));

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>mat[i][j];

    cout<<solve_pond(mat, visited)<<endl;
}