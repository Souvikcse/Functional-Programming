#include<bits/stdc++.h>
typedef long long ll;
#define Size(a) (int)sizeof(a)/sizeof(a[0])
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
using namespace std;

int main(){
    int n;
    cin>>n;
    typedef pair<int, int> ii;
    map<ii, string> table;
    for(int i=0;i<n;i++){
        ii code;
        string name;
        cin>>code.first>>code.second;
        cin>>name;
        table[code]=name;
    }
    int t;
    cin>>t;
    while(t--){
        ii code;
        cin>>code.first>>code.second;
        cout<<table[code]<<endl;
    }
    
}