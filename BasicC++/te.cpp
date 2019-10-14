
// Sample code to perform I/O:

#include <bits/stdc++.h>

using namespace std;

int main() {
string s;
cin>>s;
transform(s.begin(), s.end(), s.begin(), ::tolower);
string ans="";
string ar="love";
int pos=0;
for(int i=0;i<s.length();i++){
    if(ar[pos]=s[i]){
        ans.append(ar.substr(pos,1));
    
        pos++;
    }
    
}

    if(ans.compare("love")==0)
     cout<<"I love you, too!";
    else
     cout<<"Let us breakup!";
}


// Write your code here
