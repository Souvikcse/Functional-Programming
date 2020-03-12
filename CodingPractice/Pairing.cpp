#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>
using namespace std;

unordered_map<int, int> umap;
void dfs(int node, vector<vector<int>> v, bool *visited, int c){
    visited[node]=true;
    if(umap.find(c)==umap.end())   umap[c]=1;
    else
        umap[c]++;

    for(int i=0;i<v[node].size();i++){
        int child= v[node][i];
        if(!visited[child])
            dfs(child, v, visited, c);
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    int x, y;

    vector<vector<int>> v(n);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bool *visited= new bool[n];
    memset(visited, false, sizeof(visited));
    int comp=1;
    for(int i=0;i<n;i++){
        if(!visited[i])
            dfs(i, v, visited, comp++);
    }
    long long ans=0;
    auto it= umap.begin();
    int rest=0;
    for(int i=0;i<umap.size()-1;i++){
        int x=it->second;
        ans+= x*(n-x-rest);
        rest+=x;
        it++;
    }
    cout<<ans<<endl;
}