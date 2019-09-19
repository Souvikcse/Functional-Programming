#include<bits/stdc++.h>
typedef long long ll;
#define Size(a) (int)sizeof(a)/sizeof(a[0])
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
using namespace std;

string s[101];
bool compare(string x, string y){
    string xy = x.append(y);
    string yx = y.append(x);

    return (xy.compare(yx) > 0);
}
int main(){
    int t;
    cin>> t;
    while (t--)
    {
        int n;
        cin>>n;
        REP(0, n, 1){
          cin>>s[i];
        }
        sort(s, s+n, compare);
        REP(0, n, 1){
            cout<<s[i];
        }
        cout<<"\n";
    }
}