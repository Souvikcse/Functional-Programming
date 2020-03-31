#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int, unordered_set<int>> ump;
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[n];
        ump[ar[n]].insert(i);
    }
    
}