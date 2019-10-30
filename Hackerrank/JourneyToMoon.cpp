#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> v[100002];
bool visited[100002];
unordered_map<int, int> umap;
// Complete the journeyToMoon function below.
void dfs(int node, int count){
    visited[node]=true;
    umap[count]++;
    for(int x:v[node]){
        if(!visited[x])
            dfs(x, count);
    }
}
int journeyToMoon(int n, vector<vector<int>> astronaut, int p) {
    memset(visited, false, (n+1)*sizeof(bool));
    for (int i = 0; i < p; i++) {
        int src=astronaut[i][0];
        int dest=astronaut[i][1];

        v[src].push_back(dest);
        v[dest].push_back(src);
    }
    int count=1;
    for(int i=0;i<n;i++){
        if(!visited[i]){ 
                umap[count]=0;
                dfs(i, count);
                count++;
            }
    }
    ll sum=0, sqsum=0;
    for(auto it=umap.begin();it!=umap.end();it++){
        int val=it->second;
       // cout<<it->first<<val<<" "<<endl;
        sum+=val;
        sqsum+= (val*val);
    }
    sum*=sum;
    cout<< sum<<" "<<sqsum<<endl;
    int ans= (sum - sqsum)/2;

    return ans;
}
int main(){
    int n, p;
    cin>>n>>p;

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int result = journeyToMoon(n, astronaut, p);

    cout << result << "\n";

}