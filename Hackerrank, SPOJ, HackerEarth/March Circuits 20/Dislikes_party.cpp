#include<iostream>
#include<map>
typedef long long int ll;
using namespace std;

int main(){
    map<pair<int, int>, int> ump;
    ll n;
    cin>>n;
    ll total = (n*(n-1))/2;
    int a, b, x, y;
    for(int i=0;i<10;i++){
        cin>>a;
        for(int j=0;j<9;j++){
            cin>>b;
            x = min(a, b);
            y = max(a, b);
            if(ump.find(make_pair(x, y)) == ump.end()){
                total -= 1LL;
                ump[make_pair(x, y)] = 1;
            }
        }
    }
    
    cout << total << endl;
}