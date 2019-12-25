#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

int a[11];
set<string> ans;
void generatePermutations(int mask, int pos, int n, string out){
    if(pos==n){
        if(ans.find(out)==ans.end()){
        cout<<out<<"\n";
        ans.insert(out);
        }
        return;
    }
    for(int i=0;i<n;i++){
        if((mask&(1<<i))==0){
            generatePermutations(mask|(1<<i) , pos+1, n, out+to_string(a[i])+" ");
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];

    sort(a, a+n);
    generatePermutations(0, 0, n, "");
    cout<<endl;
}