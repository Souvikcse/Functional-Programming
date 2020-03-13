#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> v[1002];
int count;
void dfs(int node, bool *visited){
    visited[node]=true;
    for(int i=0;i<v[node].size();i++){
        if(!visited[v[node][i]]){
            count++;
            dfs(v[node][i], visited);
        }
    }
}
int main(){
    int n, d;
    cin>>n>>d;

    int x, y;
    for(int i=0;i<d;i++){
        cin>>x>>y;
        v[x-1].push_back(y-1);
    }
    int ans=n;
    bool *visited = (bool*)calloc(n, sizeof(bool));
    for(int i=0;i<n;i++){
        count=1;
        if(!visited[i]){
            dfs(i, visited);
            ans=min(ans, count);
        }
    }
    cout<<ans<<endl;
}