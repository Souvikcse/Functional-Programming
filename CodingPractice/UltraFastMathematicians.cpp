#include<iostream>
#include<cstring>
typedef long long ll;
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
using namespace std;

string s1,s2;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>s1>>s2;
        string ans="";
        REP(0, s1.length(), 1){
            if(s1[i]!=s2[i]){
                ans.append("1");
            }
            else{
                ans.append("0");
            }  
        }
        cout<<ans<<endl;
    }
}