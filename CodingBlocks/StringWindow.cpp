#include<bits/stdc++.h>
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
typedef long long ll;
using namespace std;

int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    if(s1.length() < s2.length()){
        cout<<"No string";
        return 0;
    }
    unordered_map<char, int> umap;
    REP(0, s2.length(), 1){
        umap[s2[i]]=1;
    }
    
}