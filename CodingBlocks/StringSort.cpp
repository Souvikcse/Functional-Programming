#include<iostream>
#include<cstring>
#include<algorithm>
typedef long long ll;
#define Size(a) (int)sizeof(a)/sizeof(a[0])
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
using namespace std;

string s[1001];
bool compare(string s1, string s2){
    if (s1.find(s2)==0 || s2.find(s1)==0)
        return s1.length()>s2.length();

    return s1.compare(s2)<0;
}
int main(){
    int t;
    cin>>t;
    REP(0, t, 1){
        cin>>s[i];
    }
    sort(s, s+t, compare);
    REP(0, t, 1){
        cout<<s[i]<<"\n";
    }
}