#include<iostream>
#include<vector>
#include<cmath>
typedef long long ll;
using namespace std;

vector<int> v;
void insert(int n){
    if(n == 0 || n == 1){
        v.push_back(n);
        return;
    }
    insert((int) floor(n/2));
    v.push_back(n%2);
    int len=v.size();
    for(int i=0;i<(len-1);i++)
        v.push_back(v[i]);
}
int main(){
    int n, l, r;
    cin>>n>>l>>r;
    insert((float)n);
    int count=0;
    for(int i=l-1;i<=(r-1);i++)
        if(v[i]==1)
            count++;
    
    cout<<count<<"\n";
}