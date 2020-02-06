#include<bits/stdc++.h>
using namespace std;

int g[1001][1001];
bool visited[1001];
int BFS(int start, int n){
    queue<int> q;
    q.push(start);
    visited[start]=true;

    unordered_map<int, int> umap;
    umap[start]=0;
    while (!q.empty()) {
       int node= q.front();
       q.pop();
       for(int i=1;i<=n;i++){
           if(g[node][i] && !visited[i]){
               q.push(i);
               visited[i]=true;
               umap[i]=umap[node]+6;
           }
       }
    }
    for(int i=1;i<=n;i++){
        if(i!=start){
            if(!visited[i])
            cout<<"-1"<<" ";
        else
            cout<<umap[i]<<" ";}
    }
    umap.clear();
    cout<<endl;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                g[i][j]=0;
                
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            g[x][y]=6;
            g[y][x]=6;
        }
        int s;
        cin>>s;
        memset(visited, false, sizeof(visited));
        BFS(s, n);
    }
}