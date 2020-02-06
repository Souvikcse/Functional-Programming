#include<bits/stdc++.h>
using namespace std;

void solve(int pos, string str, string* table, string* searchIn, string sub){
    if(pos==str.length()){
        for(int i=0;i<11;i++){
            if(searchIn[i].find(sub)!=-1)
                cout<<searchIn[i]<<"\n";
        }
        return;
    }
    string key=table[str[pos]-'0'];
    for(int i=0;i<key.length(); i++){
        solve(pos+1, str, table, searchIn, sub+key[i]);
    }
}
int main(){
    string str;
    cin>>str;
   string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
   string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku" };
    solve(0, str, table, searchIn, "");
}