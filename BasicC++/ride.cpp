
/*
ID: sayanwi1
LANG: C++11
PROB: ride
*/

#include <iostream>
#include<fstream>
#include<string>

using namespace std;

ifstream fin("ride.in");
ofstream fout("ride.out");

int MOD(string s, int m){
    int ans = 1;
    for(int i=0;i<s.length();i++){
        int x = (int)(s[i]-'A');
        x++;
        ans = (x*ans)%m;
    }
    return ans;
}
 int main() {
// string s;
// cin>>s;
// transform(s.begin(), s.end(), s.begin(), ::tolower);
// string ans="";
// string ar="love";
// int pos=0;
// for(int i=0;i<s.length();i++){
//     if(ar[pos]=s[i]){
//         ans.append(ar.substr(pos,1));
    
//         pos++;
//     }
    
// }

//     if(ans.compare("love")==0)
//      cout<<"I love you, too!";
//     else
//      cout<<"Let us breakup!";
    string s1, s2;
    getline(fin, s1);
    getline(fin, s2);
    if(MOD(s1, 47)==MOD(s2, 47))
        fout<<"GO\n";
    else 
       fout<<"STAY\n";
}


