#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int count = 0;
void dfs(int u, vector<int> *v, bool* vis, int par_child){
    vis[u] = 1;
    for(int i=0;i<v[u].size();i++){
        if(!vis[v[u][i]]){
            if(par_child>1e6)
                dfs(v[u][i], v, vis, v[u].size());
            else
                dfs(v[u][i], v, vis, v[u].size()-1);
            }
    }
    int children = par_child>1e6? v[u].size():v[u].size()-1;
    if(children>par_child)
        count++;
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<int> v[n];
    int x, y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        v[x-1].push_back(y-1);
        v[y-1].push_back(x-1);
    }
    bool vis[n];
    memset(vis, 0, sizeof(vis));
    for(int i=0;i<n;i++){
        if(!vis[i])
            dfs(i, v, vis, 1e7);
    }
    cout << count << endl;
}