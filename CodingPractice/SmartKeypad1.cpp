#include<iostream>
#include<cstring>
using namespace std;

void generate(string input, string *table, int pos, string out){
    if(pos==input.length()){
        cout<<out<<"\n";
        return;
    }
    int x=input[pos]-'0';
    for(int i=0;i<table[x].length();i++){
        generate(input, table, pos+1, out+table[x][i]);
    }
}
int main(){
    string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
    string in;
    cin>>in;
    generate(in, table, 0, "");
}