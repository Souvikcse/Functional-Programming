#include<bits/stdc++.h>
using namespace std;

vector<int> ve[100001];
int parent[100001];
bool visited[100001];

void DFS(int node, priority_queue<int> pq){
    visited[node]=true;
    for(int x:ve[node]){
        if(!visited[x]){
            parent[x]=node;
            DFS(x, pq);
        }
        else if(parent[node]!=x){
            pq.push(x);
        }
    }
}
void PointofFailure(int n){
    priority_queue<int> pq;
    memset(visited, false, n*sizeof(visited));
    for(int i=0;i<n;i++){
        if(!visited[i])
            DFS(i, pq);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            x-=1;
            y-=1;
            ve[x].push_back(y);
            ve[y].push_back(x);
        }
        PointofFailure(n);
        cout<<endl;

        for(int i=0;i<n;i++)
            ve[i].clear();
    }
}