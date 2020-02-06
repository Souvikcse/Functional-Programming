#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

unordered_map<int, char> umap;
set<string> v;
void solve(int pos, string s, string out){
    if(pos>=s.length()){
        v.insert(out);
        return;
    }
    int p=stoi(s.substr(pos, 1));
    solve(pos+1, s, out+umap[p]);
    
    p=stoi(s.substr(pos, 2));
   // cout<<p<<" ";
    if(p<=26){
    solve(pos+2, s, out+umap[p]);
    }
}
int main(){
    for(int i=1;i<=26;i++){
        umap[i]=(char) i+96;
    }
    int n;
    cin>>n;
    string s=to_string(n);
    solve(0, s, "");
    cout<<"["<<*v.begin();
    for(auto it=++v.begin();it!=v.end();it++){
        cout<<", "<<*it;
    }
    cout<<"]";
}