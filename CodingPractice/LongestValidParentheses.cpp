#include<iostream>
#include<stack>
using namespace std;

int main(){
    string s;
    cin>>s;

     stack<pair<char, int>> st;
        int ans = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')    st.push(make_pair('(', i));
            else{
                if(!st.empty() && st.top().first=='('){
                    ans = max(ans, i-st.top().second+1);
                    st.pop();
                    if(!st.empty())     ans = max(ans, i-st.top().second);
                    else                ans = max(ans, i-0+1);
                }
                else   st.push(make_pair(')', i));
            }
        }
    cout << ans << endl;
}