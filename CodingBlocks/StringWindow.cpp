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
    int left=0, right=0;
    unordered_map<char, int> umap;
    unordered_map<char, int> vmap;
    int window=0;
    REP(0, s2.length(), 1){
        umap[s2[i]]++;
     }
    window= umap.size();
    string ans="";
    int min=INT_MAX;
    while (right<s1.length())
    {
        if(vmap.size() < window){
            if(umap.count(s1[right]) > 0){
                vmap[s1[right]]++;
            }
            right++;
        }
        else{
            if(min > right-left){
                min=right-left;
                ans=s1.substr(left, min);
            }
            if(umap.count(s1[left]) > 0){
                vmap[s1[left]]-=1;
                if (vmap[s1[left]]==0){
                   vmap.erase(s1[left]);
                }   
            }
            left++;
        }
    }
    if(ans.compare("")==0)
        cout<<"No string";
    else
        cout<<ans; 
}