#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;

vector<pair<int, int>> v[3002];
class compare{
    public:
    bool operator()(iPair x, iPair y){
        return x.second < y.second;
    }
};
void shortest_path(int src, int V){
    set<iPair, compare> pq;

    vector<int> dist(V+1, INT_MAX);
    dist[src]=0;
    pq.insert(make_pair(src, 0));

    while(!pq.empty()){
        int node= pq.begin()->first;
        pq.erase(pq.begin());

        for(auto i=v[node].begin();i!=v[node].end();i++){
            int v= i->first;
            int weight= i->second;
            if(dist[v] > (dist[node]+weight)){
                pq.erase(make_pair(v, dist[v]));
                dist[v] = dist[node]+weight;
                pq.insert(make_pair(v, dist[v]));
            }
        }
    }
    for(int i=1;i<=V;i++) {
        if(dist[i]<0 || dist[i]>100000005)  dist[i]=-1;
        if(i!=src)    cout<<dist[i]<<" ";
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int N, E;
        cin>>N>>E;

        int x, y, r;
        for(int i=0;i<E;i++){
            cin>>x>>y>>r;
            v[x].push_back(make_pair(y, r));
            v[y].push_back(make_pair(x, r));
        }
        int S;
        cin>>S;
        shortest_path(S, N);
        for(int i=0;i<=N;i++)
            v[i].clear();
        cout<<"\n";
    }
}