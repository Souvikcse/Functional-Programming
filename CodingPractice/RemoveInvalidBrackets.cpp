#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

bool is_Balanced(string s){
    stack<char> st;
    for(char x:s){
        if(x=='(')  st.push('(');
        if(x==')'){
            if(st.empty())   return false;
            else     st.pop();
        }
    }
    return st.empty();
}
vector<string> removeInvalidParentheses(string s) {
    queue<string> q;
    q.push(s);

    unordered_map<string, int> vis;
    bool found = false;
    vector<string> ans;
    int ans_len=0;
    while(!q.empty()){
        string node = q.front();
        q.pop();
        if(vis[node])   continue;
        vis[node]=1;
        int l = node.length();
        if(is_Balanced(node)) 
            if((found && l==ans_len) || (!found))     ans_len=l, found=1, ans.push_back(node);
        if(found)   continue;
        for(int i=0;i<l;i++){
            if(node[i]=='(' || node[i]==')'){
                string new_nd = node.substr(0, i)+node.substr(i+1, l-i-1);
                q.push(new_nd);
            }
        }
    }
    return ans;
}
int main(){
    string s="(a)())()";
    vector<string> ans = removeInvalidParentheses(s);
    for(string x:ans){
        cout<<x<<"\n";
    }
}