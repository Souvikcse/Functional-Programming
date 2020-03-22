#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

unordered_map<string, int> umap;
unordered_map<int, string> invmap;
vector<int> v[101];
void dfsTopological(int n, int k){
    list<int> order;
    
    // //cout<<order.size();
    // auto it=order.begin();
    // for(int i=0;i<order.size();i++){
    //     torder[*it] = i;
    // }
    //order.sort(compare);
    cout<<"Case #"<<k<<": Vivek should drink beverages in this order:";
    for(auto it=order.begin();it!=order.end();it++){
        cout<<" "<<invmap[*it];
    }
    cout<<".\n"<<endl;
}
int main(){
    int n;
    int k=1;
    while(scanf("%d", &n)!=EOF){
        int num=n;
        int no=0;
        string vertex;
        while(n--){
            cin>>vertex;
            umap.insert(make_pair(vertex, no));
            invmap.insert(make_pair(no, vertex));
            no++;
        }
        int m;
        cin>>m;
        string x, y;
        while(m--){
            cin>>x>>y;
            v[umap[x]].push_back(umap[y]);
        }
        //memset(comp, 0, sizeof(comp));
        dfsTopological(num, k);

        for(int i=0;i<=num;i++)
            v[i].clear();

        umap.clear();
        invmap.clear();
        k++;
    }
}