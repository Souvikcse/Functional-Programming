#include<iostream>
#include<cstring>
#include<vector>
typedef long long ll;
typedef unsigned long long ull;
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
#define MOD 1000000000
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<ull> v;
    REP(0, n, 1){
        ull num;
        cin>>num;
        v.push_back(num);
    }
    if(n>=130){
        cout<<"Yes";
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    if((v[i]^v[j]^v[k]^v[l])==0){
                        cout<<"Yes";
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"No";
}