#include<bits/stdc++.h>
using namespace std;

class Data{
    public:
    int val;
    int component;
};
bool compare(Data o1, Data o2){
    if(o1.component==o2.component)
        return o1.val<o2.val;

    return o1.component<o2.component;
}
Data a[100001];
map<int, int> mp;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int k=0;
        for(int i=0;i<n;i++){
            if(k%m==0)
                k=0;

            Data ob;
            cin>>ob.val;
            ob.component=k;
            a[i]=ob;
            k++;
        }
        sort(a, a+n, compare);
        
    }
}